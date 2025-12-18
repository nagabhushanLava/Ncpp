#include<iostream>
#include<cstring>
using namespace std;
 class mystring{
private: int length;
         char *data;
public: mystring(const char *c="")
{
        length=strlen(c);
        data=new char[strlen(c)+1];
        strcpy(data,c);

}
mystring(const mystring& c){

length=c.length;
data = new char[strlen(c.data)+1];
strcpy(data,c.data);
}
mystring( mystring&& obj)
{
    cout<<"move constructor got called";
   
    length=obj.length;
    data=obj.data;
    obj.length=0;
   obj.data=nullptr;
}

mystring& operator=(mystring&& obj)
{
    cout<<"move operator got called";
    if(this!=&obj)
    {
        delete [] data;
        length=obj.length;
    
    data=obj.data;
    obj.length=0;
   obj.data=nullptr;
        
    }
    
    return *this;
}
 
mystring& operator=(const mystring& c)
{if(this!=&c)
    
    {delete [] data;
        length=c.length;
        data = new char[strlen(c.data)+1];
        strcpy(data,c.data);
    

    
    }

    return *this;
}

~mystring()
{
    delete [] data;
}

int size() const{
    return length;
}

friend ostream& operator<<(ostream& c,const mystring& s)
{

    c<<s.data;
    return c;
}

 }
;



int main()
{

    mystring s="india";
  //cout<<s;
   mystring p;
   p=move(s);
   cout<<p<<" "<<p.size();



    return 0;
}