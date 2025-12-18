#include<iostream>
using namespace std;

class area{
    //to resolve below out put issue we need to use below declaration 
    //virtual int get_area()
    public: virtual int   get_area(){
        cout<<"calling base class"<<endl;
        return 1;
    }
    area(int l,int b):length(l),brath(b){};
    protected:
    int length , brath;
};

class squire :public area{
    public : squire(int l, int b):area(l,b){}
    int get_area(){
        cout<<"calling squre area  "<<endl;;
        return length*brath;

    }
};
class rectangle: public area{

    public:rectangle(int l,int b):area(l,b){}
    int get_area(){
        cout<<"calling rectangle area "<<endl;
        return length*brath;
    }

};

int main()
{
    area *a;

    squire s(5,10);

    rectangle r(10,78);

    a=&s;
    int x;
    x=a->get_area();
    cout<<x<<endl;
    a= &r;

    x= a->get_area();

    cout<<x<<endl;
    area * v;
    squire f(10,78);
    v= static_cast<area*>(&f);
    int y =v->get_area();
    cout<<"\n value "<<y;

    return 0;
}