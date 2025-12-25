#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class listNode{
    public: int data;
            listNode * next;
            listNode(int val):data(val),next(nullptr){}
};
class lists{
    private: listNode *  head;
    public: lists():head(nullptr){}
            void insert(int val);
            void display();
            void displayRev(listNode * temp);

};
void lists::insert(int val)
{
    if(head==nullptr)
    {
        head=new listNode(val);
    }
    else{
        listNode * temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=new listNode(val);
    }
}
void lists::display()
{
    displayRev(head);
}
void lists::displayRev(listNode *  temp)
{
if(temp==nullptr)
{
    return ;
}

displayRev(temp->next);
cout<<temp->data;
if(temp!=head)
{
    cout<<"-->";
}

}
int main()
{

    lists * temp=new lists();
    temp->insert(10);
    temp->insert(20);
    temp->insert(30);
    temp->insert(40);
    temp->insert(50);
    temp->display();
return 0;
}