#include <iostream>
#include <semaphore>
#include <thread>

using namespace std;
// global binary semaphore instances
// object counts are set to zero
// objects are in non-signlaed state

binary_semaphore smphSignalMainToThread{0}, smphSignalThreadToMain{0};

void ThreadProc()
{
    // wait for a signal from the main proc
    // by attempting to decrement the semaphore
    smphSignalMainToThread.acquire();

    // this call blocks until the semaphore's count
    //  is increased from the main proc
    cout << "[thread] Got the signal\n"; // response message

    this_thread::sleep_for(chrono::seconds(3));

    cout << "[thread] send the signal\n"; // message

    // signal the main proc back
    smphSignalThreadToMain.release();
}

int main()
{
    // create some worker thread
    thread thrWorker(ThreadProc);

    cout << "[main] send the signal\n"; // message

    // signal the worker thread to start working
    //  by increasing the semphore's count
    smphSignalMainToThread.release();

    // wait until the worker thread is done doing the work
    // by attempting to decrement the semaphore's count
    smphSignalThreadToMain.acquire();

    cout << "[main] Got the signal\n"; // response message
    thrWorker.join();

    return 0;
}