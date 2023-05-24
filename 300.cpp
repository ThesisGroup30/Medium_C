#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);  // Initialize dp array with 1 as the default length of each element itself
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);  // Update the length of LIS if a longer subsequence is found
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());  // Find the maximum length in dp array
    }
};
