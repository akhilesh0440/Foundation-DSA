#include <iostream>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>
#include <sstream>

using namespace std;

string get_thread_id()
{
    auto myid = this_thread::get_id();
    stringstream ss;
    ss << myid;
    string mystr = ss.str();
    return mystr;
}

class Object
{
public:
    int _num;
    Object(int num) : _num(num) {}
    void doSomething() { cout << "Object doing something." << endl; }
};

class ObjectPool
{
public:
    queue<shared_ptr<Object>> pool;
    int poolSize;
    mutex mutex_;

    ObjectPool(int size) : poolSize(size)
    {
        cout << "Object Pool Constructed " << endl;
        for (int i = 0; i < poolSize; ++i)
        {
            cout << "Object " << i << endl;
            pool.push(make_shared<Object>(Object(i)));
        }
    }

    shared_ptr<Object> acquireObject()
    {
        unique_lock<mutex> lock(mutex_);
        if (!pool.empty())
        {
            auto obj = pool.front();
            printf("Thread %s acquired object : %d\n", get_thread_id().c_str(), obj->_num);
            pool.pop();
            return obj;
        }
        return nullptr;
    }

    void releaseObject(shared_ptr<Object> obj)
    {
        unique_lock<mutex> lock(mutex_);
        printf("Thread %s acquired object : %d\n", get_thread_id().c_str(), obj->_num);
    }
};

void workder(ObjectPool &pool)
{
    for (int i = 0; i < 15; ++i)
    {
        auto obj = pool.acquireObject();
        if (obj)
        {
            // Simulate some work;
            int worked_for = rand() % 100;
            this_thread::sleep_for(chrono::milliseconds(worked_for));
            pool.releaseObject(obj);
        }
        else
        {
            printf("Thread %s failed to acquire object\n", get_thread_id().c_str());
        }
    }
}

int main()
{
    ObjectPool pool(3);
    vector<thread> workers;
    int worker_count = 3;

    for (int i = 0; i < worker_count; i++)
    {
        workers.emplace_back(workder, ref(pool));
    }

    for (int i = 0; i < worker_count; i++)
    {
        workers[i].join();
    }
    return 0;
}