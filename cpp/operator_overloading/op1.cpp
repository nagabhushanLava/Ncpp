#include<bits\stdc++.h>
using namespace std;

class op1{

    public : int a;
             double b;
             op1(int a1,double b1):a(a1),b(b1){}
             op1( const op1 &f)=delete;
            void operator=(const op1 &g)=delete;
            bool operator==(const op1 &v)
            {
                if((a==v.a)&&(b==v.b))
                {
                    return true;
                }
                else{
                    return false;
                }
            }
};

int main()
{
    op1 f(1,3.4);
    op1 g(2,3.7);
    bool val;
    val= (f==g);

    cout<<"the result = "<<val<<endl;

    op1 u(2,8.9);
    op1 v(2,8.9);

    val= (u==v);
    cout<<"the result = "<<val;

}