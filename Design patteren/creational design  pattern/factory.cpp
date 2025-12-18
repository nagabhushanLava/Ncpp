#include<iostream>
using namespace std;

class shape{

    public: virtual void draw()=0;
            virtual ~shape(){}

};
class circle:public shape{

    public : void draw(){
        cout<<"drawing circle"<<endl;

    }
};

class squre: public shape{
    public: void draw(){
        cout<<"drawing squre"<<endl;

    }
};

class shapeFactory{
    public :virtual shape * createshape()=0;
            virtual ~shapeFactory(){}


};

class circleFactory:public shapeFactory{
    public : shape * createshape() {
        return new circle();
    }

};

class squreFactory: public shapeFactory{
    public: shape * createshape()
    {
        return new squre();

    }
};

int main()
{

shapeFactory* ptr1=new circleFactory();
shapeFactory* ptr2=new squreFactory();

shape * circle= ptr1->createshape();
shape * squre= ptr2->createshape();

circle->draw();
squre->draw();

delete ptr1;
delete ptr2;
delete circle;
delete squre;



    return 0;
}