#include<iostream>
using namespace std;
static void globalfun(){
    cout<<"i am global static function "<<endl;
}
class base
{   
    public : static int counter;
     static void  fuction()
    {

        counter++;
        cout<<"the counter value"<<counter<<endl;
    }

};
int base::counter=0;
int main(){

    globalfun();
    base b1,b2;
    b1.fuction();
    b2.fuction();
    base::fuction();
    base::counter=10;
    base::fuction();
    return 0;
}