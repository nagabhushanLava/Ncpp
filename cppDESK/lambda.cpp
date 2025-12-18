#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class student{
    public: int subs[6];
            void input(student);
            int calculateTotalScore(student i);
    
    
};

void student :: input(student v)
{
    cout<<"enter the values on array"<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>v.subs[i];
    }
    return ;
}
int student :: calculateTotalScore(student x)
{ 
    //cout<<"in calculation"<<endl;
    int temp=0;
    for(int i=0;i<6;i++)
    {
        temp=temp+x.subs[i];
    }
   // cout<<temp;
    return temp;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> v1;
  std::cout<<"enter the value of n"<<endl;
   cin>>n;
   student s1[n];
   student *s;
   for(int i=0;i<n;i++)
   {
       s->input(s1[i]);
       std::cout<<"retunr "<<endl;
        v1[i]=s->calculateTotalScore(s1[i]);
   }
   int k;
   k=*max_element(v1.begin(),v1.end());
   for(int j=0;j<v1.size();j++)
   {
    if(k==v1[j])
    {
       std:: cout<<j;
    }
   }
   
    return 0;
}
