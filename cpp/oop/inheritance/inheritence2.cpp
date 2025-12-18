#include<iostream>
using namespace std;

class base1{

    public: int c;
            float g;
            base1()
            {
                c=10;
                g=11;

            }
};

class base2{

    public: int a;
            float b;
            base2()
            {

                a=13;
                b=14;
            }


};

class derived: public base1,protected base2
{
   public: void printd()
    {
        cout<<"i am from base 2"<<a<<endl;
        cout<<"i am from base 2"<<b<<endl;
        cout<<"i am from base 1"<<c<<endl;
        cout<<"i am from base 1"<<g<<endl;

    }

};

int main()
{
    derived obj;
    obj.printd();


    return 0;
}