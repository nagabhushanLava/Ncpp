
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
int main()
{
    //std::queue<T> ;std::cout<<"Hello World";
    vector<int> v={1,2,3,1,2,1,1};
    
    map<int,int> m;
    
    int s=v.size();
    
    for(int i=0;i<s;i++)
    {
        if(m.find(v[i])!=m.end())
        {
            m[v[i]]++;
        }
        else{
            m.insert({v[i],1});
        }
    }
    
  
    
   int maxk;
   int maxv=INT_MIN;
   
   for(auto &a:m)
   {
       if(a.second>maxv)
       {
           maxv=a.second;
           maxk=a.first;
       }
   }
    
    cout<<"result maxk "<<maxk;
    
    
    
    return 0;
}