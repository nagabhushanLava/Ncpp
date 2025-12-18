#include<iostream>
#include<string>
using namespace std;
class con{

    public:string s1;
    con(string a1)
    {
        s1=a1;
    }
    con operator+(con obj)
    {
        //s1.append("_____");
        s1.append(obj.s1);
        return s1;
    }

};

int main()
{
string d1="Nagabhu",d2="shan_s";
con n1(d1);
con n2(d2);
con n3=n1+n2;
cout<<"the result="<<n3.s1<<endl;


    return 0;
}