#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the vector in ascending order
        int n = nums.size();
        int min_value = nums[0];
        int max_value = nums[n - 1];
        int result = max_value - min_value;

        for (int i = 0; i < n - 1; i++) {
            // Calculate the possible maximum and minimum values after modifying nums[i]
            int possible_max = max(nums[i] + k, max_value - k);
            int possible_min = min(nums[i + 1] - k, min_value + k);
            result = min(result, possible_max - possible_min);
        }

        return result;
    }
};
