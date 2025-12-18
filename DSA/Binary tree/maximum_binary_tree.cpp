#include<bits\stdc++.h>

using namespace std;

class node{

public : int data;
         node * left;
         node * right;

node(int d)
{
    data=d;
    left=nullptr;
    right=nullptr;
}
node(const node &n)=delete;
node operator=(const node &n)=delete;
};
int maxdepth(node *root)
{   
    if(root== nullptr)
    {
        return 0;

    }
    int l=maxdepth(root->left);
    int r=maxdepth(root->right);

    return max(l,r)+1;
}
int main()
{
      //            1
    //            /   \
    //            2    3
    //          /  \
    //          4   5
    node *root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    //root->left->left=new node(4);
    //root->left->right=new node(5);
   // root->left->left->left=new node(6);
    //root->right->right=new node(7);
    cout<<maxdepth(root);
}