#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class def{

    public: int as;
            def():as(10){};
            void operator-()
            {
                as--;
                cout<<as<<endl;
            }
};

int main()
{
    def a;
    -a;

    return 0;
}