#include<iostream>
#include<fstream>
#include<string>        
using namespace std;

int main()
{
    ifstream file("s1.txt");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    string line;
    while(getline(file,line))
{
cout<<line<<endl;
}
    file.close();
 
    cout << "File read successfully." << endl;

return 0;
}