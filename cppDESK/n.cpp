// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <thread>
#include<vector>
using namespace std;
class r{
    public: int fg;
            double gh;
            string s;
            std::vector<long> v;
            r()
            {
                fg=0;
                gh=9.0;
                s="India";
                
            }
};
int main() {
    // Write C++ code here
    cout << "Try programiz.pro"<<endl;
    r f;
    r *h=new r();
    r *g=&f;
    
    cout<<f.s<<endl;
    cout<<h->s<<endl;
    cout<<g->s<<endl;
    cout<<"f  address = %x"<<&f<<endl;
    cout<<"h holds address = %x"<<h<<endl;
    cout<<"g holds address = %x"<<g<<endl;
    g->s="ghj";
    r *j[208979]={new r()};
    
    for(long i=0;i<208979;i++)
    {
        j[i]=h+i;
        cout<<"%x"<<j[i]<<endl;
    }
    cout<<f.s<<endl;
    return 0;
}