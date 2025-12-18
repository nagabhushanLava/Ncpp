#include<iostream>
#include<thread>
#include<mutex>


using namespace std;
mutex mtx;
static int counter=0;

void fun()
{
for(int i=0;i<100000;i++)
{
    if(mtx.try_lock())
    {
        counter++;
        //ut<<"the counter :"<<counter<<endl;
        mtx.unlock();
    }
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