class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert the integers to strings
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }
        
        // Sort the strings using custom sorting function
        sort(numStrs.begin(), numStrs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        
        // Concatenate the sorted strings
        string result;
        for (string numStr : numStrs) {
            result += numStr;
        }
        
        // Handle leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        if (i == result.size()) {
            return "0";
        } else {
            return result.substr(i);
        }
    }
};
