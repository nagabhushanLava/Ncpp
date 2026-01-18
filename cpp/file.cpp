#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main()
{
    ofstream file("a.txt");  // open file for writing
    if(!file.is_open())
    {
        cerr<<"failed to open "<<endl;
        return -1;
    }

    string s;
    cout<<"enter the data into txt file"<<endl;
    getline(cin,s);        // read a line from user
    file<<s<<endl;         // write it to file
    file.close();          

    return 0;
}

