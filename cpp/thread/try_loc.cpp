#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
mutex mtx1,mtx2;
int x=0,y=0;

void dosomething()
{
    this_thread::sleep_for(chrono::seconds(1));

}
void setxy(mutex& m,int& xory, const char *ptr )
{
    for(int i=0;i<5;i++)
    {
        m.lock();
        xory++;
        cout<<ptr<<xory<<endl;
        m.unlock();
        dosomething();

    }
}

void consumexy()
{

    int usecount=5;
    int xory=0;
    while(1)
    {
        int loc_result=try_lock(mtx1,mtx2);
        if(loc_result==-1)
        {
            if(x!=0&&y!=0)
            {
                --usecount;
                xory+=x+y;
                x=0;
                y=0;
                cout<<"x + Y:"<<xory<<endl;
            }
            mtx1.unlock();
            mtx2.unlock();
            if(usecount==0) break;
        }
    }
}


int main()
{
    thread t1(setxy,ref(mtx1),ref(x),"x: ");
    thread t2(setxy,ref(mtx2),ref(y),"y: ");
    thread t3(consumexy);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}