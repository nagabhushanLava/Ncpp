#include<iostream>
#include<memory>
using namespace std;


class gen{
  
  public: int a;
  
      gen(int o){
        a=o;
      }
  
    void read()
    {
      cout<<a<<endl;
    }
};

int main()
{
  unique_ptr<gen> ptr=make_unique<gen>(45);
  ptr->read();
  
  shared_ptr<gen> ptr1=make_shared<gen>(59);
  shared_ptr<gen> ptr2=ptr1;
  ptr2->read();
  ptr1->read();
  
  cout<<"number of use cont "<<ptr1.use_count()<<endl;
  
  
  weak_ptr<gen> ptr3=ptr1;
  if(auto temp=ptr3.lock())
  {
  temp->read();
  }  
  
  
  
  return 0;
}