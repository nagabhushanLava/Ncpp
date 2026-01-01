#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* data;
    size_t len;

public:
    /* 1️⃣ Default constructor */
    MyString() : data(nullptr), len(0) {}

    /* 2️⃣ Constructor from C-string */
    MyString(const char* str) {
        if (str) {
            len = strlen(str);
            data = new char[len + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            len = 0;
        }
    }

    /* 3️⃣ Copy constructor (deep copy) */
    MyString(const MyString& other) {
        len = other.len;
        if (other.data) {
            data = new char[len + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    /* 4️⃣ Copy assignment operator */
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    /* 5️⃣ Move constructor */
    MyString(MyString&& other) noexcept {
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }

    /* 6️⃣ Move assignment operator */
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }

    /* 7️⃣ Destructor */
    ~MyString() {
        delete[] data;
    }

    /* Length */
    size_t length() const {
        return len;
    }

    /* Indexing */
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    /* String concatenation */
    MyString operator+(const MyString& rhs) const {
        MyString temp;
        temp.len = len + rhs.len;
        temp.data = new char[temp.len + 1];
        strcpy(temp.data, data);
        strcat(temp.data, rhs.data);
        return temp;
    }

    /* Equality */
    bool operator==(const MyString& rhs) const {
        return strcmp(data, rhs.data) == 0;
    }

    /* Output */
    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << (s.data ? s.data : "");
        return os;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2;    // concatenation
    MyString s4 = s3;         // copy constructor
    MyString s5;
    s5 = s4;                  // copy assignment

    cout << s3 << endl;
    cout << "Length: " << s3.length() << endl;

    s3[0] = 'h';
    cout << s3 << endl;

    cout << (s4 == s5) << endl;
}
