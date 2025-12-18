#include<iostream>
#include<fstream>
using namespace std; 
 int main()
 {
     ofstream f1("s1.txt");
     if(f1.is_open())
     {
         cout<<"I am writing to the file."<<endl;
         f1<<"Hello, I am India."<<endl;
         f1.close();
     }

     ifstream f2("s1.txt");
     string line;
     if(f2.is_open())
     {
         while (getline(f2, line))
         {
             cout<<"Line: "<<line<<endl;
         }
         f2.close();
     }

     fstream f3("s1.txt", ios::app| ios::in | ios::out); // Open file in append mode
     if(f3.is_open())
     {
            cout<<"Appending to the file."<<endl;
            f3<<"sorry i am from BHARAT "<<endl;
            f3.seekg(0); // Move the read pointer to the beginning
            while (getline(f3, line))
            {
                cout<<"Line: "<<line<<endl;
            }
            f3.close();
        }
        else
        {
            cout<<"Failed to open the file for appending."<<endl;
     }
     
     return 0;
 }