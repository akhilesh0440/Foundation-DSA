#include <iostream>
#include <thread>

using namespace std;

void run(int count)
{
    while (count-- > 0)
    {
        cout << count << endl;
    }
    this_thread::sleep_for(chrono::seconds(5));
    cout << "Thread finished" << endl;
}

int main()
{
    thread t1(run, 10);

    cout << "Main function " << endl;
    t1.detach();
    // t1.join();

    // if (t1.joinable())
    //     t1.join();

    cout << "Main() after" << endl;
    this_thread::sleep_for(chrono::seconds(5));

    return 0;
}