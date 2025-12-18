#include <iostream>
using namespace std;
template<class T>class gh{
    
    public : T a;
        
        gh():a("india"){}
        gh(const T value):a(value){
            cout<<"parametarized constructor "<<endl;
        }
        gh(gh &&obj)noexcept{
            a=move(obj.a);
            
            cout<<"move constructor"<<endl;
        }
        gh& operator=(gh &obj){
            if(this==&obj)
            {
                return *this;
            }
            a=obj.a;
            cout<<"copy constructor"<<endl;
            return *this;
        }
        gh& operator=(gh &&obj)noexcept{
            if(this==&obj)
            {
                return *this;
            }
            a=move(obj.a);
           // obj.a=nullptr;
            cout<<"move assignment opertor"<<endl;
            return *this;}
    
    
};
int main()
{
    printf("Hello World\n");
    
    gh<string> ch("INDIA");
    gh<string> gj("56");
    gh<string> b;
    gh<string> v(move(ch));
//    b=ch;
    b=move(gj);

    return 0;
}