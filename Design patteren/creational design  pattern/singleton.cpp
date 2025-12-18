#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;
class single{
private :
static single *ptr;
single(){

    cout<<"single instance created"<<this<<endl;
}
~single(){

    delete ptr;
}


public :
single(const single &obj)=delete;
single& operator=(const single&)=delete;

static single* getinstance()
{
    if(!ptr)
    {
        ptr=new single();
    }
    return ptr;
}




};

single * single::ptr=nullptr;

int main()
{
single *gtr;
gtr=single::getinstance();
cout<<endl;
cout<<gtr;

cout<<endl;
single *y1;
y1=single::getinstance();
cout<<y1;
cout<<endl;
vector<single*> t1;
vector<thread> t;

mutex mtx;
for(int i=0;i<100000000;i++)
{
t.emplace_back([&](){
    single * ptr1=single::getinstance();
    {
        lock_guard<mutex> lock(mtx);
    t1.emplace_back(ptr1);
}});
}
for(auto &k:t)
{
    cout<<"i am waiting for join"<<endl;
    k.join();
}
//cout<<"i am the address"<<t[10]<<endl;
for(auto a:t1)
{
    cout<<a<<endl;
}
/*
vector<thread> t1;
for(int i=0;i<100;i++)
{
    t1.emplace_back()
}*/




return 0;
}