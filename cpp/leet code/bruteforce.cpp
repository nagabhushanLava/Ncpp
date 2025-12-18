#include<bits/stdc++.h>
using namespace std;
void bruteForce(const string &str, const string &pattern)
{

    int strlen;
    int pattlen;
    int found;
    strlen=str.length();
    pattlen=pattern.length();
    for(int i=0;i<strlen-pattlen;i++)
    {   int j;
        for (j = 0; j < pattlen; j++)
        {
			cout<<"j ="<<j<<"pattlen="<<pattlen<<endl;
            if (str[i + j] != pattern[j])
                break;
        }
cout<<"after for loop j ="<<j<<"pattlen="<<pattlen<<endl;
        if (j == pattlen) // Full match found
        {
            cout << "Found the pattern at index " << i << endl;
            found = true;
        }

}}

int main()
{

    string str="abracadabra";
    string patt="abr";
    bruteForce(str,patt);
    return 0;
}