#include<iostream>
using namespace std;

template<class T>
class target{
    public : virtual void run()=0;
};

template<class T>
class adaptee{
    public: void runspecific()
    {
        cout<<"run by this"<<endl;
    }
};

template<class T>
class adapter: public target<T>
{
    public: adaptee<T> * ttr;
        
            adapter(adaptee<T> * ptr):ttr(ptr){};
            void run()
            {
                ttr->runspecific();
            }
};

template<class T>
void client(target<T> * ptr)
{
    ptr->run();
}

int main(){
    
    adaptee<int> * atr=new adaptee<int>();
    adapter<int> * dtr=new adapter<int>(atr);
    client(dtr);
    return 0;
}