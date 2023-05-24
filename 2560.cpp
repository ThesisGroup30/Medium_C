#include <vector>
#include <algorithm>

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        // Base case: For the first k houses, capability is the maximum amount of money in any house
        for (int i = 0; i < k; i++) {
            dp[i] = nums[i];
        }
        
        for (int i = k; i < n; i++) {
            // The capability of the robber at the current house is the maximum of two options:
            // 1. Rob the current house and add its money to the capability of the robber k houses ago
            // 2. Skip the current house and take the capability of the robber at the previous house
            dp[i] = max(nums[i] + dp[i - k], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};
