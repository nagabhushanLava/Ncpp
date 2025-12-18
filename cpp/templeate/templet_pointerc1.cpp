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

    return 0;
}
