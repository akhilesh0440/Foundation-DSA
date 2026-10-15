#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

binary_semaphore signal_to_produce{1}, signal_to_consumer{0};
#define buff_size 5

int buff[buff_size];

void producer()
{
    while (1)
    {
        signal_to_produce.acquire();
        cout << "Produced = ";
        for (int i = 0; i < buff_size; ++i)
        {
            buff[i] = i * i; // task of producer
            cout << buff[i] << " " << flush;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << endl;
        signal_to_consumer.release();
    }
}

void consumer()
{
    while (1)
    {
        signal_to_consumer.acquire();
        cout << "Consumed = ";
        for (int i = buff_size - 1; i >= 0; --i)
        {
            cout << buff[i] << " " << flush;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << endl;
        cout << endl;
        signal_to_produce.release();
    }
}

int main()
{

    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
