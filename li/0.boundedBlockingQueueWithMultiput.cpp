#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <random>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdint>
#include <queue>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

template <typename T>
class BlockingQueue {
private:
    bool _isInitDone = false;
    int _capacity = 0;
    queue<T> _buffer;
    mutex _lock;
    mutex _writerLock;
    condition_variable _notEmpty;
    condition_variable _notFull;

    void assertInited() {
        if(!_isInitDone) {
            throw runtime_error("Init not done!");
            //cerr << "Init not done!" << endl;
        }
    }
public:
    void init(int capacity) {
        if(_isInitDone) {
            throw runtime_error("Already inited!");
        }
        if(capacity <= 0) {
            throw runtime_error("Capacity <= 0");
        }
        _capacity = capacity;
        _isInitDone = true;
    }

    T get() {
        try {
            assertInited();
        } catch (exception& e) {
            cerr << e.what() << endl;
            terminate();
        }
        unique_lock<mutex> lck(_lock);
        while (_buffer.empty()) {
            _notEmpty.wait(lck);
        }
        _notFull.notify_one();
        T ret = _buffer.front();
        _buffer.pop();
        cout << "ret " << ret << endl;
        cout << _buffer.size() << endl;
        lck.unlock();
        return ret;
    }

    void put(T obj) {
        try {
            assertInited();
        } catch (exception& e) {
            cerr << e.what() << endl;
            terminate();
        }
        unique_lock<mutex> wlck(_writerLock);
        unique_lock<mutex> lck(_lock);
        while(_buffer.size() >= _capacity) {
            _notFull.wait(lck);
        }
        _buffer.push(obj);
        _notEmpty.notify_one();
        cout << _buffer.size() << endl;
        lck.unlock();
        wlck.unlock();
    }

    void multiPut (vector<T> objs) {
        try {
            assertInited();
        } catch (exception& e) {
            cerr << e.what() << endl;
            terminate();
        }
        unique_lock<mutex> wlck(_writerLock);
        unique_lock<mutex> lck(_lock);
        for(auto o : objs) {
            while (_buffer.size() >= _capacity) {
                _notFull.wait(lck);
            }
            _buffer.push(o);
            _notEmpty.notify_one();
        }
        cout << _buffer.size() << endl;
        lck.unlock();
        wlck.unlock();
    }
};

int main() {
    BlockingQueue<int> bq;
    bq.init(10);

    vector<int> objs = {0, 1, 2, 3};
    int obj = 111;

    default_random_engine r1;
    uniform_int_distribution<int> u(0, 9);

    default_random_engine r2;
    uniform_int_distribution<int> u2(500, 1000);

    int count = 20;

    while (count--) {
        cout << "------------------" << endl;

        int choice = u(r1);
        if (choice == 0) {
            cout << "put 1" << endl;
            thread t(&BlockingQueue<int>::put, &bq, obj);
            t.detach();
        } else if (choice == 1) {
            cout << "multiput 0, 1, 2, 3" << endl;
            thread t(&BlockingQueue<int>::multiPut, &bq, objs);
            t.detach();
        } else {
            cout << "get " << endl;
            thread t(&BlockingQueue<int>::get, &bq);
            t.detach();
            // Practice of using future to get return
            /*
            future<int> fut = async(&BlockingQueue<int>::get, &bq);
            cout << "get" << fut.get() << endl;
            */
        }
        this_thread::sleep_for(milliseconds(u2(r2)));
    }

    cout << "ending..." << endl;
    this_thread::sleep_for(milliseconds(500));
    return 0;
}
