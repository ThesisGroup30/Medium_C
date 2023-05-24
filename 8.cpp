class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long result = 0;
        
        // Skip leading whitespace
        while (s[i] == ' ') {
            i++;
        }
        
        // Handle sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // Convert digits to integer
        while (isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            
            // Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }
        
        return sign * result;
    }
};
