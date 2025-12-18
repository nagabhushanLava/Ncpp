#include<thread>
#include<bits\stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
typedef long long ull;

ull Oddsum=0;
ull Evensum=0;

void findOdd(ull start, ull end)
{
    for(ull i=start;i<=end;i++)
    {
        if((i&1)==1)
        {
            Oddsum+=i;

        }
    }
}

void findEven(ull start, ull end)
{
    for(ull i=start;i<=end;i++)
    {
        if((i&1)==0)
        {
            Evensum+=i;

        }
    }
}

int main()
{
ull start= 0;
ull end=1900000000;
auto startTime=high_resolution_clock::now();
std::thread t1(findOdd,start,end);
std::thread t2(findEven,start,end);

t1.join();
t2.join();
//findOdd(start,end);
//findEven(start,end);
auto stopTime=high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stopTime-startTime);
cout<<"ODDSUM: "<<Oddsum<<endl;
cout<<"EVENSUM:"<<Evensum<<endl;
cout<<"Sec :"<<duration.count()/1000000<<endl;
    return 0;
}