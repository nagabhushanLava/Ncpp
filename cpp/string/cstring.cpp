#include<iostream>
#include<cstring>
using namespace std;

int main()
{
   // clrscr();
    char *ptr="INDIA";
   // printf("%s\n",*ptr);
    while(*ptr!='\0')
    {
        cout<<*ptr;
        ptr++;
    }

    char str []="india";
    cout<<str;
    char *r=str;
    cout<<*r;
    cout<<strlen(r);

    return 0;
}