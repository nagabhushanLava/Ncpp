#include "BinaryTree.h"

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    tree.inorder(); // Output: 1 3 4 5 7
    return 0;
}
