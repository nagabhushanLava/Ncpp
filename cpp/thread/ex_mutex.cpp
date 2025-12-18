#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
mutex m;
long long int count=0;
void add()
{  for(int i=0;i<100000;i++)
{   m.lock();
     ++count;
   m.unlock();
 //   /// std::this_thread::sleep_for(chrono::seconds(1));
}}
int main()
{
    int i=100000;
    thread t1(add);
    thread t2(add);
    //thread t3(add);
    //thread t4(add);
    //thread t5(add);
    //thread t6(add);
    //t1.detach();
    //t2.detach();
    //t3.detach();
    cout<<"the value of count "<<count<<endl;
    
    t1.join();
    t2.join();
   
    return 0;
}