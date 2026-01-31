#include<iostream>
using namespace std;

class node{
	public : int data;
		 node * next;
		 node(int val):data(val),next(nullptr){};

};

class Linked{
private: node * back;
	 node * front;

public:	Linked():front(nullptr),back(nullptr){};
void insert(int val)
{
if(back==nullptr)
{
back=front=new node(val);
}
else{
node * temp=new node(val);
temp->next=back;
back=temp;
}
}
void pop()
{

 if (back == nullptr) {
            cout << "List is empty\n";
            return;
        }
 if (back == front) {
            delete back;
            back = front = nullptr;
            return;
        }
node * temp=back;
while(temp->next!=front)
{
temp=temp->next;
}

delete front;
front=temp;
front->next=nullptr;


}

void display()
{
node* temp = back;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " ---> ";
            temp = temp->next;
        }
        cout << endl;
}
};


int main()
{


Linked l;

l.insert(1);
l.insert(2);
l.insert(3);
l.insert(4);
l.insert(5);
l.display();
l.pop();
l.display();
l.pop();
l.display();

return 0;
}

