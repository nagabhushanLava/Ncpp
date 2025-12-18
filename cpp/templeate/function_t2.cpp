#include<iostream>
using namespace std;

template<class x,class y> x fun1(x a,y b)
{

    return a;
}
int main()
{
int a ;
string  b;
a=fun1(10,"df");
b=fun1("india",7.9);
cout<<a<<endl;
cout<<b<<endl;

    return 0;
}