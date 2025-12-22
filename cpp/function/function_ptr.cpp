#include<iostream>
using namespace std;
void display(int x)
{
    cout<<"Value of x is: "<<x<<endl;
}
void  display1(int fg,int fg2)
{   cout<<"hello "<<fg<<endl;
    cout<<"hello 2nd "<<fg2<<endl;
    
}

int main(){
    
    void (*funptr)(int)=nullptr;
    funptr=&display;
    funptr(10);

    void (*funptr1)(int,int)=nullptr;
    funptr1=&display1;
    funptr1(20,30); 

    return 0;


}