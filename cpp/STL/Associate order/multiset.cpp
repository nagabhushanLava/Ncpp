/*
In C++, multiset is an associative container similar to the set, but it can store
 multiple elements with same value. It is sorted in increasing order by default,
  but it canbe changed to any desired order. It provides fast insertion, deletion 
  and search operations.
  
  */

#include<bits/stdc++.h>
using namespace std;

multiset<int> s={1,12,2,3,4,3,3,2,12,13,89,7,5,4,1};

int main()
{

    
    for(auto it : s)
    {
        cout<<" "<<it;
    }
    cout<<endl;
    s.insert(45);

    s.erase(19);

    auto i= next(s.begin(),4);
    cout<<"i="<<*i<<endl;

    for(auto u:s)
    {
        cout<<" "<<u;
    }
    cout<<endl;


    return 0;

}
