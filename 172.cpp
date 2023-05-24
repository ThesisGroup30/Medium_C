class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        // Count the number of multiples of 5 in the factorial
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }

        return count;
    }
};
