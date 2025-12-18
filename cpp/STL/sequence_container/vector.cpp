#include<bits/stdc++.h>
using namespace std;

class vecdata{

    public: vector<int> v;
            vecdata( vector<int> a):v(a){};
            void inputdata(int x)
            {
                v.push_back(x);
            }
            void display()
            {
                vector<int>::iterator it;
                for(it=v.begin();it!=v.end();it++)
                {
                    cout<<" "<<*it;
                }
                cout<<endl;

            }
            void sor(){
                sort(v.begin(),v.end());
            }
};

int main()
{
    vector<int> v={1,2,3,4,5,6,7,8,9,9,8,7,6,6,5,5,4,4,4,3,3,3,3};
    vecdata f(v);
    f.display();
    f.inputdata(100);
    f.display();
    f.sor();
    f.display();

    return 0;
}   