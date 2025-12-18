#include<bits\stdc++.h>
using namespace std;

class node 
{
    public: int data;
            node *prev;
            node *next;
            node(int d);
            node(const node &)noexcept;
            node operator=(const node &)noexcept;

};
node::node(int d)
{
data=d;
prev=nullptr;
next= nullptr;

}
class Dlinkedlist {
    public : node *head;
             node *tail;        

            void insertHead(int d);
            void insertTail(int d);

            void displayforward();
            void displayBackward();

            void deletelist(int val);

            Dlinkedlist():head(nullptr),tail(nullptr){};
            Dlinkedlist(const Dlinkedlist &)=delete;
           bool operator=(const Dlinkedlist&)=delete;
           ~Dlinkedlist();

           
};

void Dlinkedlist::insertHead(int data){
node * newNode= new node(data);
if(!head)
{
    head=tail=newNode;
}
else{
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

}

void Dlinkedlist::insertTail(int data){
    node * newNode= new node(data);
    if(!tail)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

}

void Dlinkedlist::displayforward()
{
    node * temp= head;
    while(temp)
    {   cout<<temp->data;
        if(temp->next!=nullptr)
        {
            cout<<"--->";
        }
        temp=temp->next;
    }
    cout<<endl;


}

void Dlinkedlist::displayBackward()
{
    node *temp = tail;
    while (temp)
    {
        /* code */
        cout<<temp->data;
        if(temp->prev!=nullptr)
        {
            cout<<"--->";
        }
        temp=temp->prev;
    }
    cout<<endl;
}
Dlinkedlist::~Dlinkedlist()
{
    node * temp=head;
    while(temp)
    {
        node *temp2=temp->next;
        delete temp;
        temp=temp2;
    }
    cout<<"done deleting node distructor called"<<endl;
}

void Dlinkedlist::deletelist(int val)
{
    node * temp=head;
    int flag=0;
    while (temp)
    {
        if(temp->data==val)
        {
            flag=1;
            if(temp==head)
            {
                head= head->next;
                if(head) head->prev=nullptr;
            }
            else if(temp==tail)
            {
                tail=tail->prev;
                if(tail) tail->next=nullptr;

            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            delete temp;
              if(flag)
        {
            cout<<"value found on the list and deleted"<<endl;
            displayforward();
        } 
        return;

        }
        temp=temp->next;
        
    }
    if(!flag)
    {
        cout<<"the value not fuound on the list "<<endl;

    }
    
}

int main()
{
    Dlinkedlist list;
    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertTail(35);
    list.insertTail(40);
    list.insertTail(50);

    list.displayforward();
    cout<<endl;
    list.displayBackward();
    cout<<endl;
    list.deletelist(35);
    cout<<endl;
    list.deletelist(41);
    cout<<endl;

    return 0;
}