#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

atomic<int> counter;
int times = 10000;

void run()
{
    for (int i = 0; i < times; i++)
    {
        ++counter;
    }
}
int main()
{
    thread t1(run);
    thread t2(run);

    t1.join();
    t2.join();

    cout << "Counter value : " << counter << endl;
    return 0;
}