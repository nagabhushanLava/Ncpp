#include<iostream>
#include<cstdlib>
#include<new>

using namespace std;

class loc
{
    int longitude,latitude;
    public:loc(){}
            loc(int l1,int l2):longitude(l1),latitude(l2){}
            void show()
            {
                cout<<"longitude="<<longitude<<endl;
                cout<<"latitude="<<latitude<<endl;

            }
            void * operator new(size_t s);
            void operator delete(void * p);


};
void * loc ::operator new(size_t s)
{void *p;

cout<<"in overloading new"<<endl;

p=malloc(s);
if(!p)
{
    bad_alloc ba;
    throw ba;

}
    return p;
}

void loc:: operator delete(void *p)
{
    delete p;
}

int main()
{
    loc *p1,*p2;

    try{
        p1=new loc(10,20);

    }catch (bad_alloc xa)
    {
        cout<<"allocation error"<<endl;
        return 1;
    }
    p1->show();

    delete p1;
}
