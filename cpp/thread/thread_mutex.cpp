#include<iostream>
#include<bits/stdc++.h>
#include<mutex>
#include<thread>
using namespace std;

mutex mtx;


class th{
  
  public: void print(int val);
  
};

/*
void th::print(int val)
{
  
  mtx.lock();
  cout<<"the thread val "<<val<<endl;
  mtx.unlock();
}*/

void th::print(int val)
{
  
  lock_guard<mutex> lock(mtx);
  cout<<"the thread val "<<val<<endl;
}

int main()
{
  th obj;
  
  vector<thread> s1;
  for(int i=0;i<10;i++)
  {
    
    s1.emplace_back(&th::print,&obj,i+1);
  }
  for(auto &r:s1)
  {
    r.join();
  }
  
  
  
  return 0;
}