#include<iostream>
using namespace std;

class base{
    
    public : int * ptr;
            
            base()
            {
                ptr= nullptr;
            }
            base( int a[])
            {
            
                ptr = a;
                
            }
            
            base(const base * b)
            {
                
                cout<<"pointer called"<<endl;;
                ptr=b->ptr;
            }
            base(const base &obj)
            {
                cout<<"object got called"<<endl;
                ptr=obj.ptr;
                
            }
            
            
};

int main()
{
    int * arr = new int[10];
    base * ptr = new base(arr);
    
    base * ppr = new base(ptr);
    
    base obj(arr);
    base obj2(obj);
    
   base * obj3= new base(&obj);
    
    //base obj4&obj3);
    return 0;
}