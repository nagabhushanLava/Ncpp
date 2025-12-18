#include<iostream>
using namespace std;

class node{

    public: int data ;
            node *left;
            node *right;
            node(int data)
            {   
                this->data=data;
                left=nullptr;
                right=nullptr;
            }

};

class tree{

    private: node* root;
    public: tree()
    {
        root=nullptr;
    }

        void insertnode(int val);
        node* insertRecursive(node * temp,int val);

        void preordertraversal(node * temp);
        void display_preorder();
};
void tree::insertnode(int val)
{
    root=insertRecursive(root,val);

}

node * tree::insertRecursive(node * temp,int val)
{
    if(temp==nullptr)
    {
        return new node(val);
    }
    if(val<temp->data)
    {
        temp->left=insertRecursive(temp->left,val);
    }
    else{
        temp->right=insertRecursive(temp->right,val);
    }

    return temp;
}

void tree::display_preorder()
{
    preordertraversal(root);
}

void tree::preordertraversal(node *temp)
{

   // cout<<"traversal tree "<<endl;
    if(temp==nullptr)
    {
        return ;
    }
    cout<<temp->data<<" ";
    preordertraversal(temp->left);
    preordertraversal(temp->right);

}



int main()
{

tree t;
t.insertnode(60);
t.insertnode(10);
t.insertnode(20);
t.insertnode(30);
t.insertnode(40);
t.insertnode(50);
t.insertnode(70);

t.display_preorder();


    return 0;
}