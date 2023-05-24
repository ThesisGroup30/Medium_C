#include <unordered_map>
#include <vector>

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        
        unordered_map<int, int> frequencyMap;
        int count = 0;
        
        // Build frequency map
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        // Count unique k-diff pairs
        for (auto& pair : frequencyMap) {
            int num = pair.first;
            
            if (k == 0) {
                // Count pairs with the same number occurring at least twice
                if (pair.second >= 2)
                    count++;
            } else {
                // Check if there is a complement number forming a k-diff pair
                if (frequencyMap.count(num + k))
                    count++;
            }
        }
        
        return count;
    }
};
