#include<iostream>
using namespace std;

template<class T> class gen{
private: T *ptr;

public:
        gen(T val)
{
    ptr= new T(val);

}

~gen()
{

    cout<<"distructor called"<<endl;
    delete ptr;
}

T readvalue();
void setvalue(T value);

};
template<class T> 
void gen<T>::setvalue(T value)
{

    *ptr=value;

}

template<class T>
T gen<T>:: readvalue()
{

    return *ptr;

}

int main()
{

    gen<int> a(100);
    gen<string> b("india");
    gen<float> f(1.3432);

    cout<<a.readvalue()<<endl;
    cout<<b.readvalue()<<endl;
    cout<<f.readvalue()<<endl;

cout<<"----------------------------------------------------"<<endl;

    a.setvalue(50);
    b.setvalue("BHARTH");
    f.setvalue(1.09089);

    cout<<a.readvalue()<<endl;
    cout<<b.readvalue()<<endl;
    cout<<f.readvalue()<<endl;




        gen<int> *p=new gen<int>(500);
        cout<<p->readvalue()<<endl;
        delete p;
        gen<double> *d=new gen<double>(9.8765);
        cout<<d->readvalue()<<endl;
        delete d;
        gen<string> *s=new gen<string>("Taj Mahal");
        cout<<s->readvalue()<<endl;
        delete s;   
        gen<char> *c=new gen<char>('A');
        cout<<c->readvalue()<<endl; 
        delete c;
        gen<float> *fl=new gen<float>(3.1416f);
        cout<<fl->readvalue()<<endl;
        delete fl;
        gen<long> *ln=new gen<long>(1234567890L);
        cout<<ln->readvalue()<<endl;
        delete ln;
        gen<bool> *bl=new gen<bool>(true);
        cout<<bl->readvalue()<<endl;
        delete bl;
        gen<short> *sh=new gen<short>(32000);
        cout<<sh->readvalue()<<endl;        
        delete sh;  

    return 0;
}
