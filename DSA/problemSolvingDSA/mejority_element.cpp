#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findMejar(vector<int> &v)
{
    
    map<int,int> mp;
    size_t sz=v.size();
    for(int x:v)
    {
        mp[x]++;
       /* if(mp.find(v[i])!=mp.end())
        {
            mp[v[i]]++;
        }
        else{
            int j=1;
            mp.insert({v[i],j});
        }*/
    }
    
    for(auto t:mp)
    {
    
        
        cout<<" "<<t.first<<"  "<<t.second<<endl;
    }
    
}
int main()
{
    
    vector<int> v={1,2,2,1,3,4,3,2,1,5,6,4};
    findMejar(v);
    
    
    return 0;
}