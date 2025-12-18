#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

class myclass {
    public:
        void printvalues(int val, int id);
        void start_thread(int val, int num);
};

std::mutex mtx; // Mutex for thread-safe printing

void myclass::printvalues(int val, int id) {
    for (int i = 1; i <= val; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Prevents interleaved output
        std::cout << "Thread " << id << " : " << i << std::endl;
    }
}

void myclass::start_thread(int val, int num) {
    std::vector<std::thread> t;
    for (int i = 0; i < num; i++) {
        //t.emplace_back(&myclass::printvalues, this, val, i + 1); // Using emplace_back for efficiency
        t.push_back(thread(&myclass::printvalues,val,i+1));    
    }

    for (auto& f : t) {
        f.join();
    }
}

int main() {
    myclass b;
    b.start_thread(10, 5); // 5 Threads, each printing 1 to 10

    return 0;
}