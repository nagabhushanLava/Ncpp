#include<iostream>
using namespace std;


template<class T>
class node{
    public: T data;
            node *next;
            node(T val):data(val),next(nullptr){}

};

template<class T>
class Linked{

    public : node<T> * head;
            Linked():head(nullptr){};
            void insert(T val);
            void display();
};

template<class T> void Linked<T>::insert(T val){
    node<T> * temp= new node<T>(val);
    if(head==nullptr)
    {
        head=temp;

    }
    else
    {
        node<T> * t1= head ;
        while (t1->next!=nullptr)
        {
            t1=t1->next;
        }
        t1->next=temp;
        
    }
    
}

template<class T> void Linked<T>::display()
{
    node<T> * temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;

    }
    cout<<"-->nullptr";
}

int main()
{
Linked<int> list;
list.insert(10);
list.insert(20);
list.insert(30);
list.insert(40);

cout<<"------display()-----"<<endl;

list.display();

cout<<endl;

Linked<string> lists;
lists.insert("INDIA");
lists.insert("KARNATAKA");
lists.insert("BANGALORE");
lists.insert("TIPTUR");
lists.insert("KANACHEGATTA");

lists.display();



return 0;

}

