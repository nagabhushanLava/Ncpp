/*
In C++, sets are associative container which stores unique elements in some sorted order. 
By default, it is sorted ascending order of the keys, but this can be changed as per requirement.
 It provides fast insertion, deletion and search operations.

 it's self balenceing tree binary search tree


 */

#include<bits/stdc++.h>
using namespace std;

set<int> s;
int main()
{

    s={12,13,14,0,13,14,32,1,15,16,17,18,19};
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