#include <iostream>
#include "linkedlist.h"
using namespace std;
class node;
void linkedlist::insert(int d){
node *n = new node(d);
if(head==nullptr)
{
    head=n;
}
else{
    node *temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
}
void linkedlist::display()
{
node *temp=head;
if(temp!=nullptr)
{
while (temp!=nullptr)
{
    cout<<temp->data;
    if(temp->next!=nullptr)
    {
        cout<<"-->";
    
    }
    temp=temp->next;
}
cout<<endl;
}
else{
    cout<<"node is empty"<<endl;
}
}

void linkedlist::deletenode(int d)
{
node *n1=head;
node *n2;
if(n1!=nullptr && n1->data==d)
{
    head=n1->next;
    delete n1;
    return ;
}

while (n1!=nullptr && n1->data!=d )
{   
    n2=n1;
    n1=n1->next;

}
if(n1==nullptr){return;}
if(n1->data==d)
{
    n2->next=n1->next;
    cout<<"node deleted"<<endl;
}
}
int main()
{

    linkedlist l1;
    int n,i;
      do{ 
    cout<<"enter the option "<<endl;
    cout<<"1.Insert node \n2.Display \n3.Delete node \n4.Extit"<<endl;
      cin>>n;
    switch (n)
    {
    case 1:cout<<"enter the value to node"<<endl;
        cin>>i;
        l1.insert(i);
        break;
    case 2:cout<<"Displaying node"<<endl;
        l1.display();
        break;
    case 3:cout<<"deleting node enter the value"<<endl;
            cin>>i;
            l1.deletenode(i);
            break;
    default:exit(0);
        break;
    }
    
    
}while (n!=0);
return 0;}