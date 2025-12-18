#include<bits\stdc++.h>
using namespace std;
void fun(int x)
{
    while(x-->0)
    {
        cout<<x<<endl;
    }
}

class base {

    public: void gun(int x)
    {
        while(x-->0)
        {
            cout<<x<<endl;
        }
    }
};

class im
{
public: static void guh(int x)
{
    while(x-->0)
    {
        cout<<x<<endl;

    }
}

};
int main()
{

    std::thread t1(fun,5);
    std::thread t2(fun,2);
    t1.join();
    t2.join();
    cout<<"done calling function"<<endl;
    base b;
    std::thread t4(&base::gun,&b,7);
    std::thread t3(&base::gun,&b,7);
    t4.join();
    t3.join();
    
    cout<<"done by using class"; 
    std::thread h1(&im::guh,10);
    std::thread h2(&im::guh,5);

    h1.join();
    h2.join();
    cout<<"ststic funcalled through thread\n";


return 0;
}