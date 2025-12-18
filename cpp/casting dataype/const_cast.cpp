#include<iostream>
using namespace std;

void print(int *x)
{
    *x=44;
    cout<<"x= "<<*x;
}

int main(){

    int const i=10;

    cout<<"i= "<<i<<endl;

    print(const_cast<int*>(&i));

    cout<<i<<endl;
    return 0;

}