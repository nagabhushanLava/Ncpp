#include<iostream>
using namespace std;

class base;
class another{

    public: void display(base& b);
};

class base{
private: int a;
public:base(int a):a(a){};
friend void another::display( base&);


};

void another::display(base &b)
{

    cout<<b.a;
}
int main()
{
base b(10);

another c;
c.display(b);

    return 0;
}