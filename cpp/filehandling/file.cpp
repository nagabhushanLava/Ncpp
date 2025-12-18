#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream f1("s1.txt");
    if(f1.is_open())
    {
        cout<<"i am writing file";
        f1<<"hello i am india ";
        f1.close();

    }

    ifstream f2("s1.txt");
    string line;
    if(f2.is_open())
{
    while (getline(f2,line))
    {
        /* code */
        cout<<"line= "<<line;
    }
    f2.close();

    
    
}




    return 0;
}