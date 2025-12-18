#include<iostream>
#include<memory>
using namespace std;

template<class T>
class node{

    public:
            T data;
            shared_ptr<node<T>> next;
            node(T val):data(val),next(nullptr){};

};

template<class T>
class Linkedlist{

    private: shared_ptr<node<T>> head;
    public : Linkedlist():head(nullptr){};
    void insert(T val);
    void display();
};

template<class T> void Linkedlist<T>::insert(T val)
{
shared_ptr<node<T>>  temp=make_shared<node<T>>(val);
temp->next=head;
head=temp;
}

template<class T> void Linkedlist<T>::display()
{

    auto temp=head;

    while (temp!=nullptr)
{
cout<<temp->data<<"-->";
temp=temp->next; 
}
cout<<"nullptr\n";
    
}

int main() {

    Linkedlist<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);

    cout << "Integer List: ";
    intList.display();

    Linkedlist<string> strList;
    strList.insert("World");
    strList.insert("Hello");

    cout << "String List: ";
    strList.display();

    return 0;
}