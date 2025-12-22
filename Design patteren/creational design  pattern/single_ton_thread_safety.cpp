#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Single {
private:
    static Single* ptr;
    static mutex mtx;
    
    Single() {
        cout << "Constructor called" << endl;
    }
    ~Single() {
        cout << "Destructor called" << endl;
    }

public:
    static int counter;

    static Single* getAddress() {
        if (ptr == nullptr) {
            lock_guard<mutex> lock(mtx); // Ensure thread safety
            if (ptr == nullptr) { 
                ptr = new Single();
            }
        }
        return ptr;
    }

    static void startThread(int id) {
        cout << "Thread ID: " << id << endl;
        lock_guard<mutex> lock(mtx); // Safe increment using lock_guard
        counter++;
    }

    static void caller(int id) {
        thread t1(startThread, id);
        t1.join();
    }
    Single(const Single& other) = delete;
    Single& operator=(const Single& other) = delete;    
};

int Single::counter = 0;
Single* Single::ptr = nullptr;
mutex Single::mtx;

int main() {
    Single* ptr1 = Single::getAddress();
    cout << "Pointer 1 Address: " << ptr1 << endl;

    Single* ptr2 = Single::getAddress();
    cout << "Pointer 2 Address: " << ptr2 << endl;

    ptr1->caller(1);
    ptr2->caller(2);

    cout << "Final Counter Value: " << Single::counter << endl;

    return 0;
}
