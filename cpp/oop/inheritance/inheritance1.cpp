#include<iostream>
using namespace std;

class A{
public : int a;
A(int a1)
{
    a=a1;
}
virtual void read()
{
    cout<<"the value of a"<<a<<endl;
}
};

class B:public A{

    public:int b;

        B(int aa,int bb):A(aa),b(bb){}
        
        void read(){
            cout<<"the value of b"<<b<<endl;
        }

};

class C: public B{
    public : int c;

    C(int cc,int aa, int bb):B(aa,bb),c(cc){}

    void read(){
        cout<<"the value of c"<<c<<endl;
    }


};

int main()
{
A *ptr;

C v(10,20,30);

ptr=&v;
ptr->read();

A a(100);

ptr=&a;
ptr->read();

return 0;
}