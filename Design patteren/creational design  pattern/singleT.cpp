#include <iostream>
using namespace std;

template<class T> class single{
  
  private :
  
  static single<T> *ptr;
  
  single()
   {
    cout<<"i am constructor \n";
    
  }

  
  public: 
   ~single()
  {
    cout<<"i am distructor \n";
    
// delete ptr;
  }
  
  single( const single &obj)=delete;
  single& operator=( single &obj)=delete;
  
  static single<T>* getinstence()
  {
    if(!ptr)
    {
      ptr= new single();
      
      return ptr;
    }
    
    return ptr;
  }
  
  static void cleanup()
  {
    delete ptr;
    ptr=nullptr;
  }
};
template<class T>
single<T>* single<T>::ptr=nullptr;

int main() 
{
//    cout << "Hello, World!";
  
  single<int>* ptr;
  ptr=single<int>::getinstence();
  
// delete ptr;

single<int>::cleanup();
  
    
    return 0;
}