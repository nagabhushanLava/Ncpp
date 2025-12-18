#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false; // Shared condition variable predicate

void waiting_thread() {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait until data_ready becomes true.
    cv.wait(lock, []{ return data_ready; });
    // When the wait is over, the lock is re-acquired.
    std::cout << "Data is ready. Processing data...\n";
}

void signaling_thread() {
    // Simulate work before data is ready.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        // Use lock_guard to safely update the shared state.
        std::lock_guard<std::mutex> lock(mtx);
        data_ready = true;
        std::cout << "Data is prepared, notifying waiting thread.\n";
    }
    // Notify one waiting thread.
    cv.notify_one();
}

int main() {
    std::thread t1(waiting_thread);
    std::thread t2(signaling_thread);

    t1.join();
    t2.join();
    return 0;
}
