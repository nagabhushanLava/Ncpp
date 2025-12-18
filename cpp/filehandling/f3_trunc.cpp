#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    fstream f1("s1.txt",ios::out | ios::trunc); // Open file in truncate mode
    if(f1.is_open()) {
        cout<<"file has been opend in truncate mode."<<endl;
        f1<<"I AM HINDUSTAN "<<endl;
        f1.close();
        } else {
        cout << "Failed to open the file." << endl;
    }
    return 0;
}   