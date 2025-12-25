#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<class T>class treeNode{
  public:T data;
         treeNode<T> * left;
         treeNode<T> * right;
         treeNode(T val):data(val),left(nullptr),right(nullptr){}
         
    
};


template<class T> class tree{
    private: treeNode<T> * root;
    public: tree():root(nullptr){};
    
            void insert(T val);
            treeNode<T> * insertNode(treeNode<T> * temp,T val);
            
            void preorder();
            void preorderDisplay(treeNode<T> * temp);
};


template<class T> void  tree<T>::insert(T val)
 {
     root=insertNode(root,val);
 }

template<class T> treeNode<T> * tree<T>::insertNode(treeNode<T> * temp,T val)
{
    if(temp==nullptr)
    {
        return new treeNode<T>(val);
    }
    else if(temp->data>val)
    {
        temp->left=insertNode(temp->left,val);
    }
    else {
        temp->right=insertNode(temp->right,val);
    }
    
    return temp;
}

template<class T> void tree<T>::preorder()
{
    preorderDisplay(root);
}

template<class T> void tree<T>::preorderDisplay(treeNode<T> * temp)
{
 if(temp==nullptr)
    return;
std::cout <<temp->data<<" ";
preorderDisplay(temp->left);
preorderDisplay(temp->right);
}

int main()
{
      tree<string> t;
    t.insert("INDIA");
    t.insert("Karnataka");
    t.insert("Banglore");
    t.insert("Mysore");
    t.insert("Tumkur");

    cout << "Preorder Traversal: ";
    t.preorder();
    return 0;
}