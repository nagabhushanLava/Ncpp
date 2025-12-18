#include<iostream>
#include<cstring>
using namespace std;
class base{
  
  private:string s;
          char *a;
  public:base()
  {
  
  cout<<"-------------defualt constructor"<<endl;  
    s="INDIA";
    a=new char[strlen("BHARAT")+1];
    strcpy(a,"BHARAT");
  }
  
  base(string s1,const char * A)
  {
    cout<<"-----------aurgument constructor"<<endl;
    
    s=s1;
    a= new char[strlen(A)+1];
    strcpy(a,A);
    
  }
  
  base(const base &obj)
{
  cout<<"--------------copy constructor "<<endl;
  
  s=obj.s;
  a=new char[strlen(obj.a)+1];
  strcpy(a,obj.a);
  
} 

base(base &&obj){
  cout<<"--------------move constructor"<<endl;
  s=obj.s;
  a= new char[strlen(obj.a)+1];
  strcpy(a,obj.a);
  obj.s="";
  obj.a=nullptr;
  
}

base& operator=( const base& obj)
{
    cout<<"--------------copy assignment operator------"<<endl;
  if(this!=&obj)
  {
    delete []a;
    s=obj.s;
    a=new char[strlen(obj.a)+1];
    strcpy(a,obj.a);

  }

return *this;  
  
  
}

base& operator=(base&& obj)
{
  
  cout<<"--------------------cmove assignemnet oprator"<<endl;
  if(this!=&obj)
  {
    delete []a;
    
    s=obj.s;
    a=new char[strlen(obj.a)+1];
   a=obj.a;
    obj.a=nullptr;
    obj.s="";
    
    
  }
  return *this;
  
  
  
  
}
  void get()
  {
    
    cout<<"string s="<<s<<endl;
    cout<<"char * p="<<a<<endl;
  }
};

int main()
{
  base b;
  b.get();
  
  string s="KARNATAKA";
  const char *ptr="BANGLORE";
  
  base d(s,ptr);
  d.get();
  
  base v(d);
  v.get();
  
  string n="tiptur";
 const char *g="banavara";
  
  base c(n,g);
      c.get();
      
      base f(move(c));
        f.get();
  
  base w("TUMKUR","BARELY");
      w.get();
      
      base r;
      r=w;
      
    r.get();
  
  base z;
  z=move(r);
  z.get();

r.get();  
  return 0;
}
