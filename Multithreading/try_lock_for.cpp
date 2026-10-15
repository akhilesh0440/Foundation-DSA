#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int myAmount = 0;
timed_mutex m;

// try_lock_for
/* void increment(int i)
{
    if (m.try_lock_for(chrono::seconds(2)))
    {
        ++myAmount;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
} */

void increment(int i)
{
    auto now = chrono::steady_clock::now();
    if (m.try_lock_until(now + chrono::seconds(1)))
    {
        ++myAmount;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
}

int main()
{
    thread t1(increment, 1);
    thread t2(increment, 2);

    t1.join();
    t2.join();

    cout << myAmount << endl;
    return 0;
}