#include <iostream>
#include <bits/stdc++.h>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

condition_variable cv;
mutex mtx;

static int value = 0;
bool flag = false;

// to store thread exceptions
exception_ptr eptr = nullptr;

void producer()
{
    try
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !flag; });

        // simulate exception condition (example)
        if (value > 10000)
            throw runtime_error("Producer value overflow");

        value++;
        cout << "Producer: " << value << endl;

        flag = true;
        lock.unlock();
        cv.notify_all();
    }
    catch (...)
    {
        lock_guard<mutex> lg(mtx);
        if (!eptr)
            eptr = current_exception();
    }
}

void consumer()
{
    try
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return flag; });

        if (value < 0)
            throw runtime_error("Consumer underflow");

        value--;
        cout << "Consumer: " << value << endl;

        flag = false;
        lock.unlock();
        cv.notify_all();
    }
    catch (...)
    {
        lock_guard<mutex> lg(mtx);
        if (!eptr)
            eptr = current_exception();
    }
}

int main()
{
    vector<thread> v1;

    for (int i = 0; i < 1200; i++)
    {
        v1.emplace_back(producer);
        v1.emplace_back(consumer);
    }

    for (auto &t : v1)
        t.join();

    // rethrow exception in main
    if (eptr)
    {
        try
        {
            rethrow_exception(eptr);
        }
        catch (const exception &e)
        {
            cerr << "Exception caught in main: " << e.what() << endl;
        }
    }

    return 0;
}
