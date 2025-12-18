#include<iostream>
using namespace std;

class AFG{
    private : int a, b, c;
   
    public: 
    AFG(int a,int b,int c): a(a),b(b),c(c){}
    friend void display(AFG);

};

void display(AFG s){

    cout<<"the value of a "<<s.a<<" b "<<s.b<<" c "<<s.c<<endl;
}


int main()
{
AFG s(1,2,3);

display(s);

    return 0;

}