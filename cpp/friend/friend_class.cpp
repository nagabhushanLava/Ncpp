#include<iostream>
using namespace std;
class A
{
    private: int a;
             float b;
    protected: int c;

    public:
            A(int a,float b,int c):a(a),b(b),c(c){} 
    void read()
    {
        cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;
    }
    friend class B;
            };

class B{
    public:B(A s)
    {
        s.read();
    }
};

int main()
{
A s(1,12.8,8);
B p(s);


    return 0;
}



