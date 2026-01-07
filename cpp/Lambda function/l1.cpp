#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{

    auto s=[](){
      
        cout<<"HI INDIA i am from Bengaluru"<<endl;

    };
    s();

    cout<<endl;

    auto s1=[](int a){
        cout<<"the value"<<a<<endl;
    };
    s1(10);

    cout<<endl;

    string d="Bengaluru";
    auto s2=[&](string d){
        cout<<"the city "<<d<<endl;
        d.append("BENGALORE");
        cout<<"the city "<<d<<endl;
    };

    s2(d);
    
    string z="jindal";
    auto s3=[=](string d1)
    {
        cout<<d1<<endl;
    };
    s3(z);
    string a1="INDIA";
    string a2="Bharat";
    auto s4=[](auto x1,auto x2)->auto{
        
        return x1+x2;
    };
    
    cout<<s4(a1,a2);
    cout<<s4(45.8,78);
    


return 0;
}