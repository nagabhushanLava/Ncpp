#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public: int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closestSum if currentSum is closer to target
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                ++left; // Move left pointer to increase sum
            } else if (currentSum > target) {
                --right; // Move right pointer to decrease sum
            } else {
                return currentSum; // Exact match found
            }
        }
    }

    return closestSum;
}};     
int main()
{
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = sol.threeSumClosest(nums, target);
    cout << "The sum that is closest to the target " << target << " is: " << result << endl;
    return 0;
}   