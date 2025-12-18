#include<iostream>
using namespace std;

class base 
{
private:
    /* data */
public:
    base (/* args */);
  //virtual ~base();
  //to resolve dynamically distruct an issue 
    ~base ();
};

base ::base (/* args */)
{
    cout<<"constructor base\n";
}

base ::~base ()
{
    cout<<"distructor base"<<endl;

//cout<<"distructor"<<endl;
}

class  derived : public base 
{
private:
    /* data */
public:
     derived(/* args */);
    ~ derived();
};

 derived:: derived(/* args */)
{
    cout<<"constructor derived"<<endl;
}

 derived::~ derived()
{
    cout<<"i am at dreived distructor "<<endl;
}

int main()
{
    //hear we are using static memory 

    base * p;
    derived b;
    p= &b;

/*heare below we will create dynamic meomry by both base and derived*/

derived *y=new derived();
base *t;
t=y;
delete t;

derived * ptri=new derived();
base *py= dynamic_cast<derived*>(ptri);


    return 0;
}
