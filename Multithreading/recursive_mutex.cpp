#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// Example 1: with recursion

recursive_mutex rmtx;
int buffer = 0;

void recursion(char c, int loopFor)
{
    if (loopFor < 0)
        return;

    rmtx.lock();
    cout << "Thead ID: " << c << " " << buffer++ << endl;
    recursion(c, --loopFor);
    rmtx.unlock();
}

/* int main()
{
    thread t1(recursion, '1', 10);
    thread t2(recursion, '2', 10);
    t1.join();
    t2.join();
    return 0;
} */

int main()
{
    for (int i = 0; i < 5; i++)
    {
        rmtx.lock();
        cout << "locked" << i << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        rmtx.unlock();
        cout << "unlocked" << i << endl;
    }
}