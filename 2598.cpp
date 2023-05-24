#include <unordered_set>
#include <vector>

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        for (int i = 0; ; i++) {
            if (!numSet.count(i))
                return i;
            
            if (value == 0)
                break;
            
            numSet.insert(i + value);
        }
        
        return -1;  // Unreachable code
    }
};
