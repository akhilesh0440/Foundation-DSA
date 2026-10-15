#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
Produce consumer or Bounded buffer problem

THE PROBLEM STATEMENT
    1. Producer will produce and consumer will consume with synchronization of a common buffer
    2. Until produce thread produces any data consumer thread can't consume.
    3. Threads will use condition variables to notify each othre
    5. We need mutex if we us condition_variable because CV waiits on mutex

PRODUCER threads steps:
    1.lock mutex, if sucess then go ahead othrewise wait for mutex to get there
    2. Check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
    3. insert item buffer.
    5. unlock mutex.
    5. notify consumer

CONSUMER threads steps:
    1.lock mutex, if sucess then go ahead otherwise wait for mutex to get free.
    2.check if buffer is empty and if it is, then unlock the mutex and sleep, if not then go ahead and consume.
    3, consume item from buffer
    4. unlock mutex.
    5. notify producer
*/
condition_variable cv;
deque<int> buffer;
const unsigned int maxBufferSize = 50;
int intBuffer;
bool condition = false;
mutex mu;

/* void producer(int val)
{
    while (val)
    {
        unique_lock<mutex> locker(mu);
        cv.wait(locker, []()
                { return buffer.size() < maxBufferSize; });
        buffer.push_back(val);
        cout << "Produced: " << val-- << endl;
        locker.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while (true)
    {
        unique_lock<mutex> locker(mu);
        cv.wait(locker, []()
                { return buffer.size() > 0; });
        cout << "Consumer: " << buffer.back() << endl;
        buffer.pop_back();
        locker.unlock();
        cv.notify_one();
    }
} */

void producer()
{
    for (int i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mu);
        cv.wait(lock, []()
                { return !condition; });
        cout << "Producer producing: " << intBuffer++ << endl;
        condition = true;
        lock.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    for (int i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mu);
        cv.wait(lock, []()
                { return condition; });
        cout << "Consumer consumes data: " << intBuffer << endl;
        condition = false;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    /* thread t1(producer, 100);
    thread t2(consumer); */

    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}