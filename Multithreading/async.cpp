#include <iostream>
#include <thread>
#include <algorithm>
#include <future>

using namespace std;

using ull = long int;

ull findOdd(ull start, ull end)
{
    ull OddSum = 0;
    cout << "Thread ID of find Odd: " << this_thread::get_id() << endl;

    for (ull i = start; i <= end; i++)
    {
        if (i & 1)
        {
            OddSum += i;
        }
    }
    return OddSum;
}

int main()
{
    ull start = 0, end = 1900000000;
    cout << "Thread ID: " << this_thread::get_id() << endl;
    cout << "Thread created if policy is std::launch::async!!" << endl;
    future<ull> OddSum = async(launch::deferred, findOdd, start, end);
    // future<ull> OddSum = async(launch::async, findOdd, start, end);
    // we can see a thread is returning something

    cout << "Waiting for result!!" << endl;
    cout << "OddSum: " << OddSum.get() << endl;

    cout << "Completed!!" << endl;
    return 0;
}