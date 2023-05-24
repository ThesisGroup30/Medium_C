#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int cash = 0; // Represents the maximum profit when not holding any stock
        int hold = -prices[0]; // Represents the maximum profit when holding a stock

        for (int i = 1; i < n; i++) {
            int prevCash = cash;
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, prevCash - prices[i]);
        }

        return cash;
    }
};
