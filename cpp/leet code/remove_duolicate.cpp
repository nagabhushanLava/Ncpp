/*Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
          
            sort(nums.begin(),nums.end());
    
            auto numem=unique(nums.begin(),nums.end());
    
            nums.erase(numem,nums.end());
    
            return nums.size();
        }
    };

    int main()
    {
        vector s={1,2,2,3,3,2,1,0,43};

        int v;
        Solution s1;
        v=s1.removeDuplicates(s);
        cout<<v<<endl;
        for(auto c:s)
        {
            cout<<c<<" ";
        }
        return 0;
    }