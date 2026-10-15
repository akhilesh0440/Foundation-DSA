#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m1, m2;

void task_a()
{
    while (1)
    {
        // lock(m1, m2);
        m2.lock();
        m1.lock();
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Task a " << endl;
        m1.unlock();
        m2.unlock();
    }
}

void task_b()
{
    while (1)
    {
        // lock(m2, m1);
        m1.lock();
        m2.lock();
        cout << "Task b " << endl;
        m1.unlock();
        m2.unlock();
    }
}

int main()
{
    thread th1(task_a);
    thread th2(task_b);

    th1.join();
    th2.join();

    return 0;
}