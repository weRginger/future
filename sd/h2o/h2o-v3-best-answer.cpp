#define UVIC_SOLUTION 1

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

using namespace std;
using namespace std::chrono;

#if UVIC_SOLUTION

class barrier
{
private:
    mutex m_mutex;
    condition_variable m_stage_gate;

    int bonded_h;
    int bonded_o;
    string m_molecule;

public:
    barrier():
            bonded_h(0),
            bonded_o(0)
    {}

    bool molecule_complete()
    {
        return m_molecule.size() == 3;
    }

    void print_molecule()
    {
        cout << m_molecule;
        if (std::count(m_molecule.begin(), m_molecule.end(), 'H') != 2)
            cout << " ERROR!";
        cout << endl;

        m_molecule.clear();
    }

    void process_h()
    {
        unique_lock<mutex> lock(m_mutex);

        while (bonded_h == 2)
        {
            m_stage_gate.wait(lock);
        }

        ++bonded_h;

        m_molecule += 'H';

        if (molecule_complete())
        {
            print_molecule();
            bonded_h = 0;
            bonded_o = 0;
            m_stage_gate.notify_all();
        }
    }

    void process_o()
    {
        unique_lock<mutex> lock(m_mutex);

        while (bonded_o == 1)
        {
            m_stage_gate.wait(lock);
        }

        ++bonded_o;

        m_molecule += 'O';

        if (molecule_complete())
        {
            print_molecule();
            bonded_h = 0;
            bonded_o = 0;
            m_stage_gate.notify_all();
        }
    }
};
#endif

int main()
{
    barrier b;

    minstd_rand r;
    uniform_int_distribution<int> u(0,2);

    minstd_rand r2;
    uniform_int_distribution<int> u2(10, 30);

    int count = 10;

    while(count--)
    {
        cout << "------------------" << endl;

        int batch_count = 100;
        while(batch_count--)
        {
            int choice = u(r);
            if(choice == 0) {
                thread t( &barrier::process_h, &b);
                t.detach();
            }
            else {
                thread t( &barrier::process_o, &b);
                t.detach();
            }
        }
        this_thread::sleep_for(milliseconds(500));
    }

    cout << "ending..." << endl;
    this_thread::sleep_for(milliseconds(100));
}
