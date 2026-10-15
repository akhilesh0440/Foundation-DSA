#include <iostream>
#include <thread>
#include < mutex>

using namespace std;

mutex m1;
int buffer = 0;

// EXAMPLE: 1

/* void task(const char *threadNumber, int loopFor)
{
    unique_lock<mutex> lock(m1); // Automatically lock on mutex m1;
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main()
{
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();

    return 0;
} */

void task(const char *threadNumber, int loopFor)
{
    unique_lock<mutex> lock(m1, defer_lock); //Does not call lock on mutex m1, because of defer_lock
    lock.lock(); // But then we will have to explicitly tell to lock whenever we want to lock mutex m1
    for (int i = 0; i < loopFor; ++i)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
    // lock.unlock(); is not needed as it will be unlocked in destrucotr of the unique_lock
}

int main()
{
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();

    return 0;
}