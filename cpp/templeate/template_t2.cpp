#include<iostream>
using namespace std;

template<typename T>void boubllesort(T a[], int size)
{
    
for(int i=0;i<size-1;i++)
{
    for(int j=size-1;i<j;j--)
    {
        if(a[j]<a[j-1])
        {
            swap(a[j],a[j-1]);
        }
    }
}
}
int main()
{

int a[5]={50,20,30,10,40};
int n=sizeof(a)/sizeof(a[0]);
cout<<"n ="<<n<<endl;

boubllesort<int>(a,n);

cout<<"sorted arrya\n";

for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;

float b[5]={1.4,1.3,1.2,1.1,1.5};

int z=sizeof(b)/sizeof(b[0]);

boubllesort<float>(b,z);

cout<<"sorted array \n";
for(int j=0;j<z;j++)
{
    cout<<b[j]<<" ";
}
cout<<endl;

char s[5]={'z','x','v','n','a'};
int x=sizeof(s)/sizeof(s[0]);
boubllesort<char>(s,x);
cout<<"sorted array \n";
for(int n=0;n<x;n++)
{
    cout<<s[n]<<" ";
}
cout<<endl;
return 0;
}