#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    
    vector<int> v={1,2,3,4,5,11,2,1,2,1,3,4,2,1,3,5,6};
    for(auto x:v)
    {
        cout<<x;
        cout<<endl;
    }
    cout<<"element at 5\n"<<v.at(5);
    cout<<"first element "<<v.front()<<endl;
    cout<<"the last element in vector "<<v.back()<<endl;
    v.insert(v.begin(),100);
    v.erase(v.end());
    
    cout<<"the first element"<<v.front()<<endl;
    cout<<"after deleting the value "<<v.back()<<endl;
    
    
    cout<<*max_element(v.begin(),v.end())<<endl;
    cout<<"the min element in vector"<<*min_element(v.begin(),v.end())<<endl;
    
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        cout<<" "<<x;
        
    }
    reverse(v.begin(),v.end());
    cout<<"\n";
    
    for(auto y:v)
    {
        cout<<" "<<y;
    }
    cout<<endl;
   cout<< count(v.begin(),v.end(),1);
   cout<<endl;
   
  v.erase(unique(v.begin(),v.end()),v.end());
   for(auto h:v)
   {
       cout<<" "<<h;
   }
   cout<<endl;
    vector<string> b={"INDIA","RUSIA","USA","BRITAIN"};
    b.erase(b.begin()+3,b.end());
    auto it=find(b.begin(),b.end(),"USA");
    cout<<"the value "<<it-b.begin();
    sort(b.begin(),b.end());
    for(auto x:b)
    {
        cout<<" "<<x;
    }
    cout<<"\n";
    cout<<"vector size"<<b.size()<<endl;
    
    return 0;
}