#include<iostream>
using namespace std;

class base{
public: virtual ~base()
{

}
    virtual void read()
    {
        cout<<"hi i am base"<<endl;
    }

}
;

class derived : public base{
            ~derived(){}
    public : void read()
    {
        cout<<"hi  i am derive "<<endl;
    }

};

int main()
{
base * b = new derived();

derived *d = dynamic_cast<derived*>(b);

b->read();
d->read();



    return 0;
}