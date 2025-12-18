#include<iostream>
using namespace std;

//creating class of node, member are  data and pointer 
class node{
public : int data ;
        node *next;
     node(int val)
{
data=val;
next=nullptr;
}

};

class linkedlist{
        private: node *head;

        public: void insertion(int data);
                void prepend(int data);
                void display();
                linkedlist();


};

linkedlist :: linkedlist(){
    head = nullptr;

}

void linkedlist::insertion(int value)
{
node *n1= new node(value);
if(head==nullptr)
{
    head=n1;
}
else 
{
    node *temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
        temp->next=n1;
    

}
}
void linkedlist::prepend(int value)
{
    
    node *n1=new node(value);
    n1->next=head;
    head=n1;

}
void linkedlist::display()
{



node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;

}
int main()
{
    linkedlist l1;
int opt;
int data=0;
do{
cout<<"\t\t\t------hi welcome to singly linkedlist----\t\t\t\n"<<endl;
cout<<"\t\t\t------enter the option below to preform operation\t\t\t\n\n";
cout<<"\t\t\t------1)inerst linked list at the end-----\t\t\t\n";
cout<<"\t\t\t------2)insert list at prepend------------\t\t\t\n";
cout<<"\t\t\t------3)Display----------------------------\t\t\t\n";
cout<<"\t\t\t------4)exit program-----------------------\t\t\t\n";

cin>>opt;
switch(opt){
    case 1:cout<<"enter the value to be inserted \n";
           cin>>data;
           l1.insertion(data);
            break;

    case 2:cout<<"enter the value to prepend\n";
            cin>>data;
            l1.prepend(data);
            break;
    case 3:l1.display();
            break;
}

}while(opt!=4);
    return 0;
}