#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;
mutex mtx1;
condition_variable cv;
bool ready =false;


void worker(){
    cout<<"thread started and is in waiting state "<<endl;
unique_lock<mutex> lock(mtx1);
cv.wait(lock,[](){return ready; });
    cout<<"worker thread proceed after proceeding wait"<<endl;
}


int main()
{
    thread t(worker);
    this_thread::sleep_for(chrono::seconds(10));
    lock_guard<mutex>lock(mtx1);
    ready =true;
    
    cv.notify_all();
    t.join();

    return 0;
}