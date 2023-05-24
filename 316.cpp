#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        std::unordered_map<char, int> lastOccurrence;
        std::unordered_set<char> visited;
        std::stack<char> stk;
        
        // Store the last occurrence index of each character
        for (int i = 0; i < n; i++) {
            lastOccurrence[s[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            // If the character is already visited, skip it
            if (visited.count(c))
                continue;
            
            // Remove the characters from the stack that are greater than the current character
            while (!stk.empty() && stk.top() > c && lastOccurrence[stk.top()] > i) {
                visited.erase(stk.top());
                stk.pop();
            }
            
            stk.push(c);
            visited.insert(c);
        }
        
        std::string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};
