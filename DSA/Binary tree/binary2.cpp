#include<iostream>
using namespace std;

template<class T> 
class node{

    public : T data;
             node * left;
             node * right;

             node(T val):data(val),left(nullptr),right(nullptr){};

};
template<class T>
class binary_tree{
    public : node<T> * root;

             binary_tree():root(nullptr){};

             void insert(T val){
                 if(root == nullptr){
                     root = new node<T>(val);
                 }else{
                     insert_helper(root, val);
                 }
             }

             void insert_helper(node<T> * current, T val){
                 if(val < current->data){
                     if(current->left == nullptr){
                         current->left = new node<T>(val);
                     }else{
                         insert_helper(current->left, val);
                     }
                 }else{
                     if(current->right == nullptr){
                         current->right = new node<T>(val);
                     }else{
                         insert_helper(current->right, val);
                     }
                 }
             }

                void inorder_traversal(node<T> * current){
                    if(current == nullptr) return;
                    inorder_traversal(current->left);
                    cout << current->data << " ";
                    inorder_traversal(current->right);
                }   
                void inorder(){
                    inorder_traversal(root);
                }       
                void preorder_traversal(node<T> * current){
                    if(current == nullptr) return;
                    cout << current->data << " ";
                    preorder_traversal(current->left);
                    preorder_traversal(current->right);
                }

                void preorder(){
                    preorder_traversal(root);
                }
                void postorder_traversal(node<T> * current){
                    if(current == nullptr) return;
                    postorder_traversal(current->left);
                    postorder_traversal(current->right);
                    cout << current->data << " ";
                }   
                void postorder(){
                    postorder_traversal(root);
                }       
                int height(node<T> * current){
                    if(current == nullptr) return 0;
                    int left_height = height(current->left);
                    int right_height = height(current->right);
                    return max(left_height, right_height) + 1;
                }       
                int height(){
                    return height(root);
                }                   
                int count_nodes(node<T> * current){
                    if(current == nullptr) return 0;
                    return 1 + count_nodes(current->left) + count_nodes(current->right);
                }           
                int count_nodes(){
                    return count_nodes(root);
                }       
                int count_leaves(node<T> * current){
                    if(current == nullptr) return 0;
                    if(current->left == nullptr && current->right == nullptr) return 1;
                    return count_leaves(current->left) + count_leaves(current->right);
                }       


                int count_leaves(){
                    return count_leaves(root);
                }
                bool search(node<T> * current, T val){
                    if(current == nullptr) return false;
                    if(current->data == val) return true;
                    if(val < current->data) return search(current->left, val);
                    else return search(current->right, val);
                }       
                bool search(T val){
                    return search(root, val);
                }
                void clear(node<T> * current){
                    if(current == nullptr) return;
                    clear(current->left);
                    clear(current->right);
                    delete current;
                }                               
                void clear(){
                    clear(root);
                    root = nullptr;
                }
                void print_tree(node<T> * current, int level = 0){
                    if(current == nullptr) return;
                    print_tree(current->right, level + 1);
                    cout << string(level * 4, ' ') << current->data << endl;
                    print_tree(current->left, level + 1);
                }               
                void print_tree(){
                    print_tree(root);
                }       

                ~binary_tree(){
                    clear();
                }       
};

int main() {
    binary_tree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);

    cout << "Inorder Traversal: ";
    bt.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    bt.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorder();
    cout << endl;

    cout << "Height of tree: " << bt.height() << endl;
    cout << "Number of nodes: " << bt.count_nodes() << endl;
    cout << "Number of leaves: " << bt.count_leaves() << endl;

    int search_val = 4;
    cout << "Searching for " << search_val << ": " 
         << (bt.search(search_val) ? "Found" : "Not Found") << endl;

    cout << "Tree structure:" << endl;
    bt.print_tree();


    bt.clear();
    cout << "Tree cleared." << endl;    
    
    binary_tree<string> str_bt;
    //str_bt.insert("apple"); 
    str_bt.insert("banana");
    str_bt.insert("cherry");    
    str_bt.insert("date");
    str_bt.insert("fig");       
    str_bt.insert("grape");
    str_bt.insert("kiwi");
    str_bt.insert("apple"); 
    cout << "Inorder Traversal of string tree: ";
    str_bt.inorder();   
    cout << endl;   
    cout << "Preorder Traversal of string tree: ";
    str_bt.preorder();      
    cout << endl;       
    cout << "Postorder Traversal of string tree: ";         
    str_bt.postorder();
    cout << endl;                   
    
    str_bt.print_tree();    
    cout << "Height of string tree: " << str_bt.height() << endl;
    cout << "Number of nodes in string tree: " << str_bt.count_nodes() <<   endl;
    cout << "Number of leaves in string tree: " << str_bt.count_leaves()                    

    << endl;
    string search_str = "banana";
    cout << "Searching for \"" << search_str << "\": " 
         << (str_bt.search(search_str) ? "Found" : "Not Found") << endl;        

    str_bt.clear();
    cout << "String tree cleared." << endl;

    return 0;
}           
