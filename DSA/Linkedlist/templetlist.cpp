#include<iostream>
using namespace std;

template<class T>class  node{
  
  public: T data;
          node<T> *next;
          node(T val):data(val),next(nullptr){};
};

template<class T>class linkedlist{
  
  private: node<T> * root;
  
  public: linkedlist()
  {
    root=nullptr;
  }
    
    void addlist(T data)
    {
      node<T> *temp = new node<T>(data);
      if(root==nullptr)
      {
        root = temp;
      }
      else{
         node<T> *t1=root;
        while(t1->next!=nullptr)
        {
          
          t1=t1->next;
          
        }
        t1->next=temp;
      }
      
  
    }
    
    void display()
    {
      node<T> *temp=root;
      
      while(temp!=nullptr)
      {
        cout<<" "<<temp->data;
        temp=temp->next;
        
      }
      
    }
    
};

int main()
{
  
  linkedlist<int>list;
  
  list.addlist(10);
  list.addlist(20);
  list.addlist(30);
  list.addlist(40);
  list.display();
  
  cout<<endl;
  
  linkedlist<char> l;
  l.addlist('a');
  l.addlist('b');
  l.addlist('c');
  l.addlist('d');
  l.display();
  
  cout<<endl;
  linkedlist<string> s;
  s.addlist("INDIA");
  s.addlist("USA");
  s.addlist("USSR");
  s.addlist("France");
  s.display();
  
  return 0;
}