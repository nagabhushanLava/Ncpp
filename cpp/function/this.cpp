#include<iostream>
using namespace std;

class Example {
    private:
        int a;
    public:
        Example(int val) : a(val) {}
        Example& operator=(const Example& obj) {
            if (this == &obj) {  // Check for self-assignment
                return *this;
            }
            this->a = obj.a;
            return *this;
        }
        void display() {
            std::cout << "a: " << &a << std::endl;
        }
    };
    
    int main() {
        Example e1(5), e2(10);
        e1 = e1; // Self-assignment
        e1.display();
    }
    