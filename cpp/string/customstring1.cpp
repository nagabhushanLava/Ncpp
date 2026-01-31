#include <iostream>
#include <cstring>
using namespace std;

class mystr {
public:
    char* ptr;
    int length;

    mystr() : ptr(nullptr), length(0) {}

    mystr(char* ttr) {
        length = strlen(ttr);
        ptr = new char[length + 1];
        strcpy(ptr, ttr);
    }

    mystr(const mystr* obj) {
        length = obj->length;
        ptr = new char[length + 1];
        strcpy(ptr, obj->ptr);
    }

    mystr& operator=(const mystr* obj) {
        if (this != obj) {
            delete[] ptr;
            length = obj->length;
            ptr = new char[length + 1];
            strcpy(ptr, obj->ptr);
        }
        return *this;
    }

    mystr(mystr*&& obj) {
        ptr = obj->ptr;
        length = obj->length;
        obj->ptr = nullptr;
        obj->length = 0;
    }

    mystr& operator=(mystr*&& obj) {
        if (this != obj) {
            delete[] ptr;
            ptr = obj->ptr;
            length = obj->length;
            obj->ptr = nullptr;
            obj->length = 0;
        }
        return *this;
    }

    ~mystr() {
        delete[] ptr;
    }
};

ostream& operator<<(ostream& os, mystr* obj) {
    os << (obj->ptr ? obj->ptr : "");
    cout << " [operator<< called]";
    return os;
}

int main() {
    char text1[] = "Hello";

    mystr b(text1);
    mystr c(&b);
    mystr d;
    d = &c;
    mystr e(std::move(&d));
    mystr f;
    f = std::move(&e);

    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    cout << &e << endl;
    cout << &f << endl;

    return 0;
}
