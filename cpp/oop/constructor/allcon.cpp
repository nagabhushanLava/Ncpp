#include <iostream>
using namespace std;

class base
{
  
  private:int a;
          float n;
  public:base()
  {
    a=10;
    n=1.9;
  }
  
  base(int c,float b):a(c),n(b){cout<<"argument constructor called"<<endl;};
  
  base(const base &b)
  {
    if(this!=&b)
    this->a=b.a;
    this->n=b.n;
    
    cout<<"copy constructor called"<<endl;
  }
  base& operator=(const base &b)
  {
    if(this!=&b)
    this->a=b.a;
    this->n=b.n;
    
    cout<<"copy operator overloading called"<<endl;
    return *this;
    
  }
  base(base &&b)
  {
    
    if(this!=&b){
    this->a=b.a;
    this->n=b.n;
    
    b.a=0;
    b.n=0;
    
    cout<<"move constructor called"<<endl;}
    
  }
  
  base& operator=(base &&b)
  {
    if(this!=&b)
    {
      this->a=b.a;
      this->n=b.n;
      
      b.a=0;
      b.n=0;
      
      cout<<"move operator called"<<endl;
      
      return *this;
      
    }
    
  }
};
int main() 
{
    cout << "Hello, World!"<<endl;
    
    base b;
    base c(10,1.89);
    base f(c);
    base d;
    d=f;
    base z=move(d);
    base x;
    x=move(z);
    
    return 0;
}