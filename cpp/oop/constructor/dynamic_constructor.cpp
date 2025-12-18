#include<iostream>
using namespace std;
class super{
    public: int a;

            super()
            {
                a=100;
                cout<<" default constructorthe value of a="<<a<<endl;
            
            }
            super(int a)
            {
                this->a=a;
                cout<<"parameterized constructor the value of a="<<a<<endl;
            }
            super(const super &obj)
            {
                this->a=obj.a;
                cout<<"copy constructor the value of a="<<a<<endl;
            }
            super(super &&obj)
            {
                this->a=obj.a;
                obj.a=0;
                cout<<"move constructor the value of a="<<a<<endl;
            }
            super& operator=(const super &obj)
            {
                this->a=obj.a;
                cout<<"copy assignment operator the value of a="<<a<<endl;
                return *this;
            }
            super& operator=(super &&obj)
            {
                this->a=obj.a;
                obj.a=0;
                cout<<"move assignment operator the value of a="<<a<<endl;
                return *this;
            }
};

int main()
{

    super * s1 =new super(); //default constructor
    super * s2 =new super(200); //parameterized constructor
    super * s3 =new super(*s2); //copy constructor
    super * s4 =new super( std::move(*s2)); //move constructor
    *s3 =*s1; //copy assignment operator
    *s4 = std::move(*s1); //move assignment operator

    delete s1;
    delete s2;      
    delete s3;
    delete s4;  
    

    return 0;

}