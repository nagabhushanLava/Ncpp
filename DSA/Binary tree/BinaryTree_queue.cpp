#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class tree {
private:
    node* root;

public:
    tree() : root(nullptr) {}

    void insert(int val) {
        root = insertNode(val, root);
    }

    node* insertNode(int val, node* temp) {
        if (temp == nullptr) {
            return new node(val);
        }

        if (val < temp->data) {
            temp->left = insertNode(val, temp->left);
        } else {
            temp->right = insertNode(val, temp->right);
        }

        return temp;   // ✅ important
    }

    void traverse() {
        if (!root) return;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
};

int main() {
    tree t;
    t.insert(100);
    t.insert(50);
    t.insert(25);
    t.insert(60);
    t.insert(150);
    t.insert(125);
    t.insert(185);

    t.traverse();
    return 0;
}
