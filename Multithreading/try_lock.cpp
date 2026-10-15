#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increaseTheCounterFor100000Time()
{
    for (int i = 0; i < 100000; ++i)
    {
        // tries locking the mutex and returns the status
        // if it locked, "mtx.try_lock()" return false
        // skip the execution of code inside the if statement
        // goes to next line to execution
        if (mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}

int main()
{
    thread t1(increaseTheCounterFor100000Time);
    thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    cout << "counter could increases upto : " << counter << endl;

    return 0;
}