class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int deletions = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] == nums[i + 1]) {
                deletions++;
                nums.erase(nums.begin() + i + 1);
                i--;  // Go back one step to recheck the new element at index i + 1
                n--;  // Update the size of the array
            }
        }
        
        return deletions;
    }
};
