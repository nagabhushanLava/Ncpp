#include <iostream>
#include <vector>
#include <string>
using namespace std;

class D{
private:
    string name;
    string USN;
    float sem;

public:
    D(string n, string u, float s) : name(n), USN(u), sem(s) {}

    void show() {
        cout << "Name: " << name << "\nUSN: " << USN << "\nSem: " << sem << endl;
    }
};

int main() {
    vector<D*> students;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name, usn;
        float sem;
        cout << "Enter name, USN, and semester for student " << i + 1 << ":\n";
        cin >> ws;               // Clear whitespace
        getline(cin, name);
        getline(cin, usn);
        cin >> sem;

        students.push_back(new D(name, usn, sem));
    }

    cout << "\n--- Student Details ---\n";
    for (auto d : students) {
        d->show();
    }

    for (auto d : students) {
        delete d;
    }

    return 0;
}
