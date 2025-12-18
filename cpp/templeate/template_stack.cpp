#include<iostream>
using namespace std;
//#define max 10;
template<class stackType> class stack{

    private: int pos;
             stackType arr[10];
    public: stack():pos(0){}
            void push(stackType val);
            stackType pop();
};

template<class stackType> void stack<stackType> :: push(stackType obj)
{
if(pos==10)
{
    cout<<"stack is full"<<endl;
    return;
}
arr[pos]=obj;
pos++;

}

template<class stackType> stackType stack<stackType>::pop()
{

    if(pos==0)
    {
        cout<<"stack is underflow"<<endl;
        return 0;
    }
    pos--;
    return arr[pos];
}

int main()
{   int i=0;
    stack<char> s1;
    s1.push('h');
    s1.push('g');
    s1.push('z');
    s1.push('c');
    s1.push('f');

    for(i=0;i<10; i++)
    {
        cout<<"the value of poping "<<s1.pop()<<endl;
    }
stack<float> f;
    f.push(1.1);
    f.push(2.1);
    f.push(3.1);
    cout<<"the value of pop"<<f.pop()<<endl;
    return 0;
}