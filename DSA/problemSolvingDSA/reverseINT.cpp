#include<iostream>
using namespace std;

int reverse(int x)
{
int rev=0;

while(x!=0)
{
    rev=rev*10+x%10;
    x/=10;
    
}

return rev;

}

int main()
{

    int n;
    cout<<"enter the value"<<endl;
    cin>>n;
    cout<<reverse(n)<<endl;

    return 0;
}