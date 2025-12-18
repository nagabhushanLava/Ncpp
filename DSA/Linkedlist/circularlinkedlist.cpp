#include<bits\stdc++.h>
using namespace std;
class node{

    public : int data;
             node *next;
            node(const node &n)=delete;
            bool operator=(const node &n)=delete;
            node(int d);

};
node::node(int d):data(d),next(nullptr){}

class Clinkedlist{

    public:void insert(int d);
            void display();
            void deletenode(int d);
            node *head;
            node *tail;
            Clinkedlist();
            ~Clinkedlist();


};
Clinkedlist::Clinkedlist():head(nullptr),tail(nullptr){}
Clinkedlist::~Clinkedlist()
{
    if (tail == nullptr) return;

        node* curr = head;
        do {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        } while (curr != head);

        head =tail= nullptr;
}
void Clinkedlist::insert(int d)
{

    node *newnode= new node(d);
    if((head==nullptr)&&(tail==nullptr))
    {
        head=newnode;
        tail=newnode;
        tail->next=head;

    }
    else
    {   newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;


    }


}
void Clinkedlist::display()
{
    if(head==nullptr)
    {
        return;
    }
   else{
     node *x=head;
    do
    {
        cout<<x->data;
        if(x->next!=head)
            cout<<"->";
        x=x->next;
    }while(x!=head);

}}

void Clinkedlist::deletenode(int d)
{

    node *prev=tail;
    node *current=head;
    node * temp;

    if(head==nullptr)
    {
        return ;
    }
    else 
    {
        if(d==head->data)
        {
           current=temp=head;
           prev->next=current->next;
           current=current->next;
           head=current;
           delete temp;
        }
        else
        {do{
            current=current->next;
            prev=prev->next;
            if((current->data==d)&&(tail->data==d))
            {
                current=temp=tail;
                prev->next=current->next;
                current=current->next;
                tail=prev;
                delete temp;
            }
            if(current->data==d)
            {
                temp=current;
                prev->next=current->next;
                current=current->next;
                delete temp;
            }


        }while(current!=head);
        }
    }
}


int main()
{
Clinkedlist list;

list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Circular Linked List: \n";
    list.display();
    cout<<endl;
    cout<<"deleting node\n";
    list.deletenode(10);
    list.deletenode(30);
    list.deletenode(50);
    list.display();
    return 0;
}
