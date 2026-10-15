#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int myAmount = 0;
mutex m;

/* void addMoneu()
{
    // will occur race condition
    // since two threads access the variable simultaneously
    ++myAmount;
} */

void addMoneu()
{
    // using the mutex to avoid race condition
    m.lock();
    ++myAmount;
    m.unlock();
}

int main()
{
    thread t1(addMoneu);
    thread t2(addMoneu);

    t1.join();
    t2.join();

    cout << myAmount << endl;
    return 0;
}