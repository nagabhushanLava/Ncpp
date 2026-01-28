#include<bits/stdc++.h>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex mtx;
queue<int> q;
condition_variable cv;


void producer()
{
    for(int i=0;i<5;i++)
    {
    unique_lock<mutex> lock(mtx);
    q.push(i);
    cout<<"produced "<<i<<endl;
}
cv.notify_one();
std::this_thread::sleep_for(chrono_seconds(5));

}

void consumer()
{

    for(int i=0;i<5;i++)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[](){return !q.empty();});
    int item=q.front();
    q.pop();

    cout<<"item poped"<<item<<endl;
    
    }
}



int main()
{

    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();


    return 0;
}