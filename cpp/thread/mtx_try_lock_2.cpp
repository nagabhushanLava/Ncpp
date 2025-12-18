#include <mutex>
#include<iostream>
#include<algorithm>
#include<thread>
#include<semaphore>
using namespace std;

mutex mtx;

static int counter=0;
counting_semaphore<1> cv(1);

void fun()
{

for(int i=0;i<100000;i++)
{
	cv.acquire();
    counter++;
        //ut<<"the counter :"<<counter<<endl;
    cv.release();
}
}
int main()
{

thread t1(fun);
thread t2(fun);

t1.join();
t2.join();

cout<<"the counter value"<<counter<<endl;

    return 0;
}







