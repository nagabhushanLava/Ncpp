#include<iostream>
using namespace std;
void rec(int v)
{   
    if(v==1)
    {   
        cout<<"1\n";
        return;
    }
    cout<<v<<" ";
    
    v--;
    rec(v);
}
long long int fact( long long  int v)
{
    if(v==1)
    {
        return 1;
    }

    return v*fact(v-1);

}
int main()
{

    cout<<fact(100)<<endl;
    //rec(4000);

    return 0;
}