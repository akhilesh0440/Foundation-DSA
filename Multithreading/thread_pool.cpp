#include <iostream>
#include <thread>
#include < mutex>
#include <queue>
#include <vector>
#include <functional>
#include <sstream>
#include <stdio.h>
#include <condition_variable>

using namespace std;

class ThreadPool
{
public:
    ThreadPool(size_t numThreads) : stop(false)
    {
        for (size_t i = 0; i < numThreads; ++i)
        {
            workers.emplace_back([this]
                                 {
    for(;;){
        unique_lock<mutex> lock(queueMutex);
        condition.wait(lock, [this] { return stop ||  !tasks.empty();});
        if(stop && tasks.empty()) return;
        auto task = std::move(tasks.front()); // Exctract task from the tasks list
        tasks.pop(); // Remove task from list as going to execute it.
        lock.unlock(); // Unlock mutex, so anothe thread can accept the task
        task(); // Run the task
    } });
        }
    }

    template <class F>
    void enqueue(F &&task)
    {
        unique_lock<mutex> lock(queueMutex);
        tasks.emplace(forward<F>(task));
        lock.unlock();
        condition.notify_one();
    }

    ~ThreadPool()
    {
        unique_lock<mutex> lock(queueMutex);
        stop = true;
        lock.unlock();
        condition.notify_all();
        for (thread &worker : workers)
        {
            worker.join();
        }
    }

private:
    bool stop;
    mutex queueMutex;
    queue<std::function<void()>> tasks;
    vector<thread> workers;
    condition_variable condition;
};

string get_thread_id()
{
    auto myid = this_thread::get_id();
    stringstream ss;
    ss << myid;
    string mystr = ss.str();
    return mystr;
}

int main()
{
    ThreadPool pool(4); // Create a pool with N number of worker threads
    cout << "Thread pool created\n";
    cout << "enqueue (Assign) some tasks \n: ";

    for (int i = 0; i < 8; ++i)
    {
        pool.enqueue([i]
                     {
        printf("Task id %s executed by thread \n", i, get_thread_id().c_str());
        this_thread::sleep_for(chrono::seconds(1)); });
    }
    return 0;
}
