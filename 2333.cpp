class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        
        // Calculate the absolute differences between nums1 and nums2
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        
        // Define the dp table with dimensions (n + 1) x (k1 + 1) x (k2 + 1)
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k1 + 1, vector<long long>(k2 + 1, 0)));
        
        // Iterate over the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k1; j++) {
                for (int k = 0; k <= k2; k++) {
                    // Calculate the current minimum sum of squared differences
                    long long minDiff = INT_MAX;
                    for (int x = 0; x <= min(j, i - 1); x++) {
                        for (int y = 0; y <= min(k, i - 1); y++) {
                            minDiff = min(minDiff, dp[i - 1][j - x][k - y] + (x + y) * (x + y) - x * x - y * y);
                        }
                    }
                    
                    // Update the dp table
                    dp[i][j][k] = minDiff + diff[i - 1];
                }
            }
        }
        
        // Return the minimum sum of squared differences
        return dp[n][k1][k2];
    }
};
