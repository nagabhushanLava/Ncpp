#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template  <class T,class X> class greece{
    public : T s;
             X z;
             virtual void getvalue()
             {
                 
                 cout<<"hi i at base()"<<endl;
                 cout<<"the value of s "<<s<<" x "<<z<<endl;
                 
             }
             greece(T b,X c):s(b),z(c){}
             
};

template <class T, class X,class F> class derived:public greece<T,X>{
    public:
            F d;
            derived(T v,X h,F n):greece<T,X>(v,h),d(n){}
    void getvalue()
    {
        cout<<"the value of d= "<<d<<endl;
        
        greece<T,X>::getvalue();
        
        
    }
};

int main()
{
    greece<int , float> * ptr=new derived<int,float,string>(10,1.2f,"King");
    
    ptr->getvalue();
    return 0;
}