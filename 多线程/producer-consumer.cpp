#include <iostream>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <thread>
using namespace std;
const int kProduceItems = 10;
const int kRepositorySize = 4;
template<class T>
class Repository {
public:
    T items_buff[kRepositorySize];
    mutex mtx; // 生产者消费者互斥量，因为两者都会涉及produce_position和consume_position的读写
    mutex produce_mutex; // 生产计数互斥量，因为只有生产者会读写produce_item_count
    mutex consume_mutex; // 消费计数互斥量，因为只有消费者会读写consume_item_count
    size_t produce_item_count;
    size_t consume_item_count;
    size_t produce_position; // 下一个生产的位置
    size_t consume_position; // 下一个消费的位置
    condition_variable repo_not_full; // 仓库不满条件变量
    condition_variable repo_not_empty; // 仓库不空条件变量
    Repository() {
        produce_item_count = 0;
        consume_item_count = 0;
        produce_position = 0;
        consume_position = 0;
    };
    void Init() {
        fill_n(items_buff, sizeof(items_buff)/sizeof(items_buff[0]), 0);
        produce_item_count = 0;
        consume_item_count = 0;
        produce_position = 0;
        consume_position = 0;
    }
};
template<class T>
class Factory {
private:
    Repository<T> repo;

    void ProduceItem(Repository<T> &repo, T item) {
        unique_lock<mutex> lock(repo.mtx);
        // +1 后判断，因为在初始时，两者位于同一位置（因此仓库中最大存在 kRepositorySize-1 个产品）
        while ((repo.produce_position+1) % kRepositorySize == repo.consume_position) {
            cout << "Repository is full, waiting..." << endl;
            (repo.repo_not_full).wait(lock); // 阻塞时释放锁，被唤醒时获得锁
        }
        repo.items_buff[repo.produce_position++] = item;
        if (repo.produce_position == kRepositorySize)
            repo.produce_position = 0;
        (repo.repo_not_empty).notify_all(); // 唤醒所有因空阻塞的进程
        lock.unlock();
    }
    T ConsumeItem(Repository<T> &repo) {
        unique_lock<mutex> lock(repo.mtx);
        while (repo.consume_position == repo.produce_position) {
            cout << "Repository is empty, waiting ..." << endl;
            (repo.repo_not_empty).wait(lock);
        }
        T data = repo.items_buff[repo.consume_position++];
        if (repo.consume_position == kRepositorySize)
            repo.consume_position = 0;
        (repo.repo_not_full).notify_all();
        lock.unlock();
        return data;
    }
public:
    void Reset() {
        repo.Init();
    }
    void ProduceTask() {
        bool ready_to_exit = false;
        while (true) {
            sleep(1); // 如果不sleep ,运行太快，一个进程会完成所有生产
            unique_lock<mutex> lock(repo.produce_mutex);

            if (repo.produce_item_count < kProduceItems) {
                ++(repo.produce_item_count);
                T item = repo.produce_item_count;
                cout << "producer id: "<< this_thread::get_id() << " is producing "
                     << item << "^th item..." << endl;
                ProduceItem(repo, item);
            } else {
                ready_to_exit = true;
            }

            lock.unlock();
            // sleep(1);
            if (ready_to_exit)
                break;
        }
        cout << "Producer thread " << std::this_thread::get_id()
             << " is exiting..." << endl;
    }

    void ConsumeTask() {
        bool ready_to_exit =false;
        while (true) {
            sleep(1); // 如果不sleep ,运行太快，一个进程会消费所有产品
            unique_lock<mutex> lock(repo.consume_mutex);

            if (repo.consume_item_count < kProduceItems) {
                T item = ConsumeItem(repo);
                cout << "consumer id: " << this_thread::get_id() << " is consuming "
                     << item << "^th item" << endl;
                ++(repo.consume_item_count);
            } else {
                ready_to_exit = true;
            }

            lock.unlock();
            // sleep(1);
            if (ready_to_exit)
                break;
        }
        cout << "Consumer thread " << std::this_thread::get_id()
             << " is exiting..." << endl;
    }
};

int main() {
    cout << "Main thread id :" << this_thread::get_id() << endl;
    class Factory<int> factory;
    thread producer1(&Factory<int>::ProduceTask, &factory);
    thread producer2(&Factory<int>::ProduceTask, &factory);
    thread producer3(&Factory<int>::ProduceTask, &factory);

    thread consumer1(&Factory<int>::ConsumeTask, &factory);
    thread consumer2(&Factory<int>::ConsumeTask, &factory);
    thread consumer3(&Factory<int>::ConsumeTask, &factory);

    producer1.join();
    producer2.join();
    producer3.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();
}
