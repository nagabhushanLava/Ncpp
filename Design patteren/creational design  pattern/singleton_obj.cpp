#include<iostream>
using namespace std;

class base{
    private: base()
    {cout<<"i am constructor\n";
        
    }
    ~base()
    {cout<<"i am distructor \n";
        
    }
    public :
    
    base(const base& obj)=delete;
    base& operator=(const base& obj)=delete;
static base& getobj()
    {
       static base obj;
        
        return obj;
        
    }
    void fun()
    {cout<<"i a  function \n"<<this;
        
    }
    
};

int main()
{
    base& obj=base::getobj();
    obj.fun();
    
    
    return 0;
}