/*
In C++, list container implements a doubly linked list in which each element contains 
the address of next and previous element in the list. It stores data in non-contiguous memory,
 hence providing fast insertion and deletion once the position of the element is known.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l={1,2,3,4,4,4,5,5,6,6};

    l.push_back(100);
    l.pop_front();
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++)
    {
        cout<<" "<<*it;

    }
    cout<<endl;


}