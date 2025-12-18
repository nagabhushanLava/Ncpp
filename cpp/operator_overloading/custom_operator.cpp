#include<iostream>
using namespace std;
class person{
private: string name;
        int age;
public: person(string s,int a):name(s),age(a){};


friend ostream& operator<<(ostream& s,const person& p);
};

ostream& operator<<(ostream& s, const person& p)
{

    s<<"the name "<<p.name<<endl<<"the age"<<p.age<<endl;

    return s;
}

int main()
{

person p("INDIA", 75);

cout<<p;








    return 0;
}