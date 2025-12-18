#include<iostream>
using namespace std;

class supper{

    public: string str;

    supper()
    {
        str="INDIA";
        cout<<"default  "<<str<<endl;

    }

    super(string s):str(s){cout<<"parameter constructor "<<str<<endl;}

    super(super &obj)
    {
        strcpy(str,obj.str);
        cout<<"copy constructor "<<str<<endl;
    }

    super& operator=(const super &obj)
    {
        if(this==&obj)
        {
            return *this;
        }
        strcpy(str,obj.str);
        cout<<"copy constructor operator "<<str<<endl;
        return *this;
    }

    super(super &&obj)
    {
        strcpy(str,obj.str);
        obj.str=nullptr;
        cout<<"move constructor"<<str<<endl;
    }
    super& operator=(super &&obj)
    {
        if(this==&obj)
        {
            return *this;
        }
        strcpy(str,obj.str);

        cout<<"move assignment operator "<<str<<endl;

        return *this;
    }
};