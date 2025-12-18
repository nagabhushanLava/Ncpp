#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
    public : T data;
            node<T> *left;
            node<T> *right;
            node(T d):data(d),left(nullptr),right(nullptr){}
};

template<class T>
class tree{
    public: node<T> *root;
            tree()
            {
                root=nullptr;
            }

            void insert(T data)
            {
                root=insertNode(root,data);
            }
            node<T>* insertNode(node<T>* root,T data) {
                if (root == nullptr) {
                    return new node<T>(data);
                }
                if (data < root->data) {
                    root->left = insertNode(root->left, data);
                } else if (data > root->data) {
                    root->right = insertNode(root->right, data);
                }
                return root;
            }   
            void inorderTraversal(node<T>* root) {
                if (root != nullptr) {
                    inorderTraversal(root->left);
                    cout << root->data << " ";
                    inorderTraversal(root->right);
                }
            }   
            void inorder() {
                inorderTraversal(root);
            }       
            void preorderTraversal(node<T>* root) {
                if (root != nullptr) {
                    cout << root->data << " ";
                    preorderTraversal(root->left);
                    preorderTraversal(root->right);
                }
            }   
            void preorder() {
                preorderTraversal(root);
            }
};

int main() {
    tree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(7);
    t.insert(2);
    t.insert(4);
    t.insert(6);
    t.insert(8);

    cout << "Inorder Traversal: ";
    t.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    t.preorder();
    cout << endl;

    return 0;
}
