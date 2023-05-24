class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        int m = chars.size();
        unordered_map<char, int> char_vals;
        for (int i = 0; i < m; i++) {
            char_vals[chars[i]] = vals[i];
        }
        int max_cost = 0, curr_cost = 0;
        for (int i = 0; i < n; i++) {
            if (char_vals.count(s[i])) {
                curr_cost += char_vals[s[i]];
            } else {
                curr_cost += s[i] - 'a' + 1;
            }
            max_cost = max(max_cost, curr_cost);
            curr_cost = max(0, curr_cost);
        }
        return max_cost;
    }
};
