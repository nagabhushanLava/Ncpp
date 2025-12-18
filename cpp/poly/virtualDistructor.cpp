#include<iostream>
using namespace std;


class shape{

    public: shape()
    {
        cout<<"parent shape construcor"<<endl;
    }
   virtual ~shape()
    {
        cout<<"parent shape distrucor\n";
    }

    virtual void print()
    {
        cout<<"parnet\n";
    }
};

class circle : public shape{

    public : circle()
    {
        cout<<"child circle construcor called\n";
    }
            ~circle()
            {

                cout<<"child circle distrucor \n";
            }

            void print()
            {
                cout<<"child\n";
            }
};

int main()
{


shape *ptr;

circle b;

ptr = &b ;

ptr->print();


    return 0;

}