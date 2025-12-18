#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx1,mtx2;
void callt1(int id)
{
mtx1.lock();
cout<<"thread 1 locked "<<endl;
mtx2.lock();
cout<<"waiting for unlock t2"<<endl;

mtx2.unlock();
mtx1.unlock();

}


void callt2(int id)
{
    mtx2.lock();
    cout<<"thread 2 locked "<<endl;
    mtx1.lock();
    cout<<"waiting for unlock mtx1"<<endl;
    
    mtx2.unlock();
    mtx1.unlock();

}

int main()
{
    thread t1(callt1,1);
    thread t2(callt2,2);
    
    t1.join();
    t2.join();

}