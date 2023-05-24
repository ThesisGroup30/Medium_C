#include <unordered_map>
#include <string>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Edge case: division by zero
        if (denominator == 0)
            return "";
        
        // Edge case: numerator is zero
        if (numerator == 0)
            return "0";
        
        string result;
        
        // Handle sign
        if (numerator < 0 ^ denominator < 0)
            result += '-';
        
        // Convert numerator and denominator to positive
        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));
        
        // Add integral part
        result += to_string(num / den);
        
        long long remainder = num % den;
        
        // Check if fraction part is zero
        if (remainder == 0)
            return result;
        
        // Add decimal point
        result += '.';
        
        // Map to store remainder and its index
        unordered_map<long long, int> remainderMap;
        
        while (remainder != 0) {
            // If the remainder repeats, enclose it in parentheses
            if (remainderMap.find(remainder) != remainderMap.end()) {
                result.insert(remainderMap[remainder], "(");
                result += ')';
                break;
            }
            
            // Store the current remainder and its index
            remainderMap[remainder] = result.size();
            
            // Perform division to get the next digit
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};
