#include <iostream>

template<typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    ~Deque() {
        while (!empty()) {
            pop_front();
        }
    }

    bool empty() const {
        return size == 0;
    }

    size_t get_size() const {
        return size;
    }

    void push_front(T val) {
        Node* newNode = new Node(val);
        if (empty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void push_back(T val) {
        Node* newNode = new Node(val);
        if (empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    void pop_front() {
        if (empty()) return;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        size--;
    }

    void pop_back() {
        if (empty()) return;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        size--;
    }

    T get_front() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return front->data;
    }

    T get_back() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return rear->data;
    }

    void display() const {
        Node* current = front;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};
int main() {
    Deque<int> dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);
    dq.display(); // Output: 5 10 15

    dq.pop_front();
    dq.display(); // Output: 10 15

    dq.pop_back();
    dq.display(); // Output: 10

    std::cout << "Front: " << dq.get_front() << "\n"; // 10
    std::cout << "Size: " << dq.get_size() << "\n";   // 1

    return 0;
}
