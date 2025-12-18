#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
double findmergedarray(vector<int>& s1, vector<int>& s2){

int w1,w2;
double mid;
int d;

w1=s1.size();
w2=s2.size();
for(int l=0;l<w2;l++)
    {   
        s1.push_back(s2[l]);

        }

sort(s1.begin(),s1.end());


d=s1.size();
d=d/2;
if((d%2)==0)
{
    cout<<s1[d]<<" "<<s1[d+1]<<endl;
mid=s1[d]+s1[d-1];
mid=mid/2;
return mid;
}
else
{
mid=s1[d];

return mid;
}

    
}


int main()
{
    double res;
    vector<int> s1={1,2};
    vector<int> s2={3,4};
    res=findmergedarray(s1,s2);    
    cout<<res;
    return 0;

}
