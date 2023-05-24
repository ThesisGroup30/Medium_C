class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorValue = 0;
        for (int i = 0; i < n; i++) {
            xorValue ^= nums[i];
        }
        int bitPos = 0;
        while ((xorValue & (1 << bitPos)) == 0) {
            bitPos++;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & (1 << bitPos)) == 0) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};
