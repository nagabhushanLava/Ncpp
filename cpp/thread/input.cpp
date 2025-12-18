#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Function that each thread will execute
void threadFunction(int id) {
    for (int i = 0; i < 5; ++i) {
        cout << "Thread " << id << " is running: " << i << std::endl;
       // this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 500 milliseconds
    }
}

int main() {
    // Create two threads
    thread t1(threadFunction, 1);
    thread t2(threadFunction, 2);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    std::cout << "Both threads have finished." << std::endl;

    return 0;
}
