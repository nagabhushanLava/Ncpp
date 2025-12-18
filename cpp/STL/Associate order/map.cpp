/*
binary search tree - read balck tree sanme as set
In C++, maps are associative containers that store data in the form of key value pairs sorted
 on the basis of keys. No two mapped values can have the same keys. By default, 
it stores data in ascending order of the keys, but this can be changes as per requirement.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<string,string> m;

class p{

    public : 
             string key;
             string value;
             void insert_(string key,string value);
             void display();
};

void p::insert_(string key,string value){

    m.insert({key,value});


}

void p::display(){

    for(auto &p_v:m)
    {
        cout<<"["<<p_v.first<<"]"<<" = "<<p_v.second<<endl;

    }

}

int main(){
p v;
v.insert_("india","barth");
v.insert_("king","queen");
p f;
f.insert_("mysore","banglore");
f.display();
m.erase("king");
f.display();
    return 0;
}