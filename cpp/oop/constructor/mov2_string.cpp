#include <iostream>
#include <cstring>
using namespace std;

class person {
public:
    string name;
    char *ptr;

    // Constructor
    person(string name1, const char *ptr1) {
        name = name1;
        ptr = new char[strlen(ptr1) + 1];
        strcpy(ptr, ptr1);

        cout << name << endl;
        cout << ptr << endl;
    }

    // Copy Constructor (Deep copy)
    person(const person &obj) {
        name = obj.name;
        ptr = new char[strlen(obj.ptr) + 1];
        strcpy(ptr, obj.ptr);
    }

    //copy assignment operator (Deep copy)
    person &operator=(const person &obj) {  
        if (this != &obj) { // Check for self-assignment
            name = obj.name;
            delete[] ptr; // Free existing memory
            ptr = new char[strlen(obj.ptr) + 1];
            strcpy(ptr, obj.ptr);
        }
        return *this;
    }   


    // Move Constructor
    person(person &&obj) noexcept {
        name = obj.name;
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    // Move Assignment Operator
    person &operator=(person &&obj) noexcept {  
        if (this != &obj) { // Check for self-assignment
            name = obj.name;
            delete[] ptr; // Free existing memory
            ptr = obj.ptr; // Transfer ownership
            obj.ptr = nullptr; // Leave moved-from object in a valid state
        }
        return *this;
    }   

    // Destructor
    ~person() {
        delete[] ptr;
    }

    void display() {
        cout << "The value name: " << name << endl;
        if (ptr)
            cout << "The value at ptr: " << ptr << endl;
        else
            cout << "ptr is nullptr" << endl;
    }
};

int main() {
    cout << "Hello World" << endl;
    char ptr[6] = "super";
    string v = "MYSORE";

    person s(v, ptr);
    person t(s);           // Copy constructor
    person g = move(s);    // Move constructor

    

    s.display(); // Accessing moved-from object; safe due to nullptr check
    t.display();
    g.display();

    return 0;
}

