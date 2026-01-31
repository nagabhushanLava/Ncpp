#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class abrstract{
    public: virtual void transport()=0;
};
class port:public abrstract{
    public: 
            void transport()
            {
                cout<<"trasport via ship"<<endl;
                
            }
            
};

class road:public abrstract{
    public: void transport()
    {
        
        cout<<"trasport via road"<<endl;
        
    }
};

int main()
{
    int option;
    abrstract * ptr=nullptr;
    do{
        cout<<"enter the option"<<endl;
        cin>>option;
        switch(option)
        {
            case 1: ptr= new port();
                    ptr->transport();
                    break;
            case 2:ptr=new road();
                    ptr->transport();
                    break;
        }
    }while(option!=0);
    
    
    
    return 0;
}
                               