#include<iostream>
#include <semaphore>
#include<thread>
using namespace std;

static int counter=0;
counting_semaphore<3> semaphore(3);

void update_counter(int id)
{cout<<"the thred id"<<id<<endl;

    semaphore.acquire();

    std::this_thread::sleep_for(chrono::seconds(10));
    counter++;
    //cout<<"the thred id"<<id<<endl;
   cout<<"the counter"<<counter<<endl;
   semaphore.release();

}

int main()
{

    thread t1(1);
    thread t2(2);
    thread t3(3);
    thread t4(4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;

}