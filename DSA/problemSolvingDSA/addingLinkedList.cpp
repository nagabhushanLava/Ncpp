#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
Node* addTwoNumbers(Node* l1, Node* l2) 
{
    Node* dummyHead = new Node(0);
    Node* p = l1, *q = l2, *curr = dummyHead;
    int carry = 0;

    while (p != nullptr || q != nullptr) 
    {
        int x = (p != nullptr) ? p->data : 0;
        int y = (q != nullptr) ? q->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;

        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    if (carry > 0) 
    {
        curr->next = new Node(carry);
    }

    return dummyHead->next;
}
void printList(Node* node) 
{
    while (node != nullptr) 
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main() 
{
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    Node* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}