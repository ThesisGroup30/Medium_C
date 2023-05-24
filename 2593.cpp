#include <vector>
#include <limits>

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);  // Track whether an element is marked or not
        long long score = 0;
        
        while (true) {
            int minIndex = -1;
            int minValue = numeric_limits<int>::max();
            
            // Find the smallest unmarked element
            for (int i = 0; i < n; i++) {
                if (!marked[i] && nums[i] < minValue) {
                    minIndex = i;
                    minValue = nums[i];
                }
            }
            
            // If no unmarked element is found, break the loop
            if (minIndex == -1) {
                break;
            }
            
            // Add the value of the chosen element to the score
            score += nums[minIndex];
            
            // Mark the chosen element and its adjacent elements
            marked[minIndex] = true;
            if (minIndex - 1 >= 0) {
                marked[minIndex - 1] = true;
            }
            if (minIndex + 1 < n) {
                marked[minIndex + 1] = true;
            }
        }
        
        return score;
    }
};
