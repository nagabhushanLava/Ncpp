#include<iostream>
using namespace std;

template<class T> 
class gen{

public:T a;

gen(T val):a(val){};

T readvalue()
{
    return a;
}};

int main()
{

gen<int> a(100);
gen<string> b("india");
gen<char *> c("INDIA");
gen<double> f(3.999999999999999);
cout<<a.readvalue()<<endl;
cout<<b.readvalue()<<endl;
cout<<c.readvalue()<<endl;
cout<<f.readvalue()<<endl;




    return 0;
}