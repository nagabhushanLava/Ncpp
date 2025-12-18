#include<iostream>
using namespace std;
class gh
{
    public : int ul;
             static int vl;
             gh()
             {
                ul =0;
             }
             static void fun()
             {  
                vl++;
                int u=0;
                cout<<"statsic fun="<<vl<<endl;
                cout<<"can i use non static variable "<<u<<endl;
                
             }
            void  fun2()
             {
                  ul++;
                  cout<<"non static fun="<<ul<<endl;
                  vl++;
                  cout<<"can i use statci variable in non static fun "<<vl<<endl;
             }
};
int gh::vl=0;
int main()
{
   gh t;
   gh::fun();
   t.fun2();
   t.fun();



    return 0;
}
