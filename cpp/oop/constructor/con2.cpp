#include <iostream>
using namespace std;

class super {
public:
    int val;
    double j;

    // Default constructor
    super() : val(0), j(0.0) {
        cout << "default constructor called" << endl;
    }

    // Parameterized constructor
    super(int v, double n) : val(v), j(n) {
        cout << "argument constructor called" << endl;
    }

    // Copy constructor
    super(const super& obj) : val(obj.val), j(obj.j) {
        cout << "copy constructor called" << endl;
    }

    // Copy assignment operator (FIXED)
    super& operator=(const super& obj) {
        if (this == &obj) {
            return *this;
        }
        val = obj.val;
        j = obj.j;
        cout << "copy assignment operator" << endl;
        return *this;
    }

    // Move constructor
    super(super&& obj) noexcept : val(obj.val), j(obj.j) {
        obj.val = 0;
        obj.j = 0.0;
        cout << "move constructor" << endl;
    }

    // Move assignment operator
    super& operator=(super&& obj) noexcept {
        if (this == &obj) {
            return *this;
        }
        val = obj.val;
        j = obj.j;
        obj.val = 0;
        obj.j = 0.0;
        cout << "move assignment operator" << endl;
        return *this;
    }

    void set() {}
};

int main() {
    cout << "Hello World" << endl;

    super s;                  // default constructor
    super v(10, 8.9);         // parameterized constructor
    v = s;                    // copy assignment operator
    super f = move(v);        // move constructor
    s = move(v);              // move assignment operator

    return 0;
}
