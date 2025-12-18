#include<iostream>
#include<cstring>
using namespace std;

class base{
    public : string str;
             char *ptr;
            //default constructor 
             base()
             {  
                 ptr=new char[1];
                 
                 ptr[0]='\0';
                 str="";
                 
             }
             //parameterized constructor
             base(string s,const char *p)
             {
                 cout<<"parameterized constructor"<<endl;
                 str=s;
                 ptr=new char[strlen(p)+1];
                 strcpy(ptr,p);
                 
             }
             
             //copy constructor
             
             base(const base& obj)
             {
                 str=obj.str;
                 ptr=new char[strlen(obj.ptr)+1];
                 strcpy(ptr,obj.ptr);
             }
             
             //copy assignment operator
             
             base& operator=(const base& obj)
             {  if(this!=&obj)
             {
                    str=obj.str;
                    delete [] ptr;
                    ptr= new char[strlen(obj.ptr)+1];
                    strcpy(ptr,obj.ptr);
                    
                 
             }
                 return *this;
             }
            
            //move constructor
            
            base(base&& obj)
            {
                
                str=obj.str;
                ptr=obj.ptr;
                obj.ptr=nullptr;
                obj.str="";
                
                
                
            }
            
            //move assignment operator
            base& operator=(base&& obj)
            {
                if(this!=&obj)
                {
                    str=obj.str;
                    delete []ptr;
                    ptr=new char[strlen(obj.ptr)+1];
                    ptr=obj.ptr;
                    obj.ptr=nullptr;
                    obj.str="";
                }
                
                return *this;
            }
            
             
};

int main()
{
    
string s="INDIA";
const char  *p="BHARAT";

base * ptr=new base(s,p);

    return 0;
}