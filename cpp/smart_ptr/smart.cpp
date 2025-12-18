#include<iostream>
#include<memory>
#include<cstring>

using namespace std;

int main()
{

    shared_ptr<int> pt1= make_shared<int>(20); 
    shared_ptr<int> pt2=pt1;

    std::cout<<*pt1;

    unique_ptr<char[]> char1=make_unique<char[]>(6);
    strcpy(char1.get(),"INDIA");
    
    cout<<char1.get();

    
    return 0;
}