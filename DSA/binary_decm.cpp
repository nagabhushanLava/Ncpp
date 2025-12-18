#include<iostream>
using namespace std;

int BtoD(int val)
{

    int ans=0;
    int  pow=1;
    while (val>0)
{
    int rem=val%10;
    ans+=(rem*pow);
    pow=pow*2;
    val/=10;


    }
    
    return ans;

}

int main()
{


    int decnum;
    cin>>decnum;
    cout<<BtoD(decnum);


    return 0;
}