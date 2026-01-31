#include<iostream>
using namespace std;

class base{
    public: virtual void run()=0;
            base()
            {
                
            }
            ~base()
            {
                cout<<"distructro called base"<<endl;
            }
};
class derived : public base{
    public : long long int *v;
    void run()
    {
        
    }
    derived()
    {
  size_t bytes = 5ULL * 1024 * 1024 * 1024;   // 5 GB in bytes
        size_t num_elements = bytes / sizeof(long long);
         v = new long long int[num_elements];
        cout<<"the value stored="<<num_elements * sizeof(long long) <<endl;
    }
    ~derived()
    {
        cout<<"derived disrtuctor called"<<endl;
    }
    
};
int main()
{
   try{
    base * ptr=new derived[100]; 
   }catch(bad_alloc& ba)
   {
    cout<<"allocation failed"<<endl;

    }        
  
    
    return 0;
}