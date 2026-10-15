#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
long balance = 0;

void addMoney(int money)
{
    lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amount Added Current Balance: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    unique_lock<mutex> ul(m);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        cout << "Amount Deducted: " << money << endl;
    }
    else
    {
        cout << "Amount Can't be deducted, current balance is less than " << money << endl;
    }
    cout << "Current Balance is: " << balance << endl;
}

int main()
{
    thread t1(withdrawMoney, 500);
    this_thread::sleep_for(chrono::seconds(5));
    thread t2(addMoney, 500);
    t1.join();
    t2.join();
}