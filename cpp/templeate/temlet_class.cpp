#include<bits/stdc++.h>
using namespace std;

template<class T>
class gen{

    public:T val;

        gen(T v):val(v){}

    public: T read()
    {
        return val;
    }


};

int main()
{

    gen<int> f(10);

int d=f.read();

    cout<<"the value of T "<<d<<endl;

    return 0;
}