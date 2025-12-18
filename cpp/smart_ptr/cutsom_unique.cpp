#include<iostream>
using namespace std;

template<class T>
class U_ptr{
    T *ptr;
public:    explicit U_ptr(T *p=nullptr):ptr(p){}
    U_ptr(U_ptr &obj)=delete;
    U_ptr& operator=(U_ptr& obj)=delete;
    
    U_ptr(U_ptr &&obj):ptr(obj.ptr){
        obj.ptr=nullptr;
        
    }
    U_ptr& operator=(U_ptr&& obj){
        if(this!=&obj)
        {
            delete ptr;
            ptr=obj.ptr;
            obj.ptr=nullptr;
        
        }
        
        
        return *this;
    }
    T* operator->()
    {
        return ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    
    
    
    
};

class base{
    public: int a;
    base()
    {
        a=100;
        
    }
    void get(){
        cout<<"i am base"<<a<<endl;
    }
    
};

int main()
{
    
    
    U_ptr<base> p(new base);
    (*p).get();
    p->get();
    
    
    return 0;
}
