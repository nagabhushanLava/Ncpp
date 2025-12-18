#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void run(int j)
{
    while(j-->0)
    {cout<<"learn cpp"<<endl;
   // std::this_thread::sleep_for(chrono::seconds(1));
    }
}
void rundetach(int g)
{
    while(g-->0)
    {
        cout<<"deatch thread cout"<<g<<endl;
        //std::this_thread::sleep_for(chrono::seconds(10));
    }
    cout<<"this thread finished"<<endl;
}
int main()
{     cout<<"main()"<<endl;
    thread t1(run,10);
    //_sleep(1);
    //cout<<"main()"<<endl;
    t1.join();
    cout<<"main() after "<<endl;


    cout<<"main()"<<endl;
    thread t2(rundetach,15);
    
    t2.detach();
    cout<<"main() bdetach after "<<endl;
    _sleep(10);
    if(t2.detachable())
        
    return 0;
}