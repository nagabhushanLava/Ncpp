/*
In C++, forward_list container provides the implementation of singly linked list data structure.
 It stores data in non-contiguous memory where each element points to the next element in the 
 sequence. This makes insertion and deletion faster once the position of the element is known.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{   
     forward_list<int> l1={1,2,3,4,5,56,6,4,3,3,2};

     l1.insert_after(l1.begin(),12);

     auto it=next(l1.begin(),4);
     *it=89;

     for(auto i:l1)
     {
        cout<<"  "<<i;


     }

     cout<<endl;



    return 0;
}