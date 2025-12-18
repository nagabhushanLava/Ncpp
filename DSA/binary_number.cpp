#include<iostream>
using namespace std;
int print(int decnumber)
{
    

int result=0;
int rem;
int pow=1;



while (decnumber>0)
{

    rem=decnumber%2;
    decnumber=decnumber/2;
    result+=(rem*pow);
    pow=pow*10;


    /* code */
}

return result;
}
int main()
{

    int i=2;
        cout<<print(2147483648);
    

    return 0;
}