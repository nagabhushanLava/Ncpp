#include<iostream>
using namespace std;
class node
{
public:    int data;
            node *left;
            node *right;
            node(int data){
            this->data=data;
            left=NULL;
            right=NULL;

            }
};

class linkedlist{

    public: node *head;
            linkedlist()
            {
                head=NULL;
            }
            void insertnode(int d);
            void display();
};
void linkedlist::insertnode(int d)
{
    node *n1= new node(d);
    if(head==NULL)
    {
        head=n1;
    }
    else{
        node *temp=head;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=n1;
        n1->left=temp;
    }

}
void linkedlist::display()
{
    node*n2= head;
    while (n2!=NULL)
    {
       // cout<<n2->data;
            //cout<<"-->";
    
       // n2=n2->right;
    }
    

}

int main()
{

linkedlist l1;
l1.insertnode(1);
l1.insertnode(2);
l1.insertnode(3);
l1.display();
    return 0;
}
