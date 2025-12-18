#include<iostream>
using namespace std;

class node{
    public: int data;
            node *left;
            node *right;
           node(int d)
{
    data=d;
    left=nullptr;
    right=nullptr;

}

};


class  binarytree
{
public :
    /* data */
    node *root;
    node * insertRecurcive(node *n,int val);
    void inorderRecurcive(node *n);
    void preorderRecurcive(node *n);
    void postorderRecurcive(node *n);
    void deleteRecurcive(node *n);
     binarytree(/* args */);
    ~ binarytree();
    void insertnode(int value);
    void inordertraversal();
    void preordertraversal();
    void postordertraversal();
};

 binarytree:: binarytree(/* args */)
{
root=nullptr;
}




 binarytree::~ binarytree()
{
    deleteRecurcive(root);

}

void binarytree :: deleteRecurcive(node *n)
{
        if(n != nullptr)
        {
            deleteRecurcive(n->left);
            deleteRecurcive(n->right);
           delete n; 
        }

}

void binarytree:: insertnode( int val)
{
    root=insertRecurcive(root,val);
}

void binarytree::preordertraversal()
{
preorderRecurcive(root);
cout<<endl;
}

void binarytree::inordertraversal()
{
inorderRecurcive(root);
cout<<endl;

}

void binarytree :: postordertraversal()
{
postorderRecurcive(root);
cout<<endl;
}


node * binarytree:: insertRecurcive(node *n, int val){

    if(n==nullptr)
    {
        return new node(val);

    }

    if(val<n->data)
{   
n->left=insertRecurcive(n->left,val);
}
else{

n->right=insertRecurcive(n->right,val);

}

return n;
}

void binarytree::inorderRecurcive(node *n)
{   if(n==nullptr) return;
    inorderRecurcive(n->left);
    cout<<n->data<<" ";
    inorderRecurcive(n->right);

}

void binarytree::preorderRecurcive(node *n)
{   if(n==nullptr) return;
    cout<<n->data<<" ";
    preorderRecurcive(n->left);
    preorderRecurcive(n->right);
}

void binarytree :: postorderRecurcive(node *n)
{   if(n==nullptr) return;
    postorderRecurcive(n->left);
    postorderRecurcive(n->right);
    cout<<n->data<<" ";
}


int main(){
binarytree tree;

    tree.insertnode(50);
    tree.insertnode(30);
    tree.insertnode(70);
    tree.insertnode(20);
    tree.insertnode(40);
    tree.insertnode(60);
    tree.insertnode(80);

    cout << "Preorder traversal: ";
    tree.preordertraversal();
    
    cout << "Inorder traversal: ";
    tree.inordertraversal();

    
    cout << "Postorder traversal: ";
    tree.postordertraversal();



    return 0;
}