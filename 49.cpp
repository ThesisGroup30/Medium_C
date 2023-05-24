#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagramGroups;
        
        for (const auto& str : strs) {
            string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            
            // Group the anagrams based on the sorted string
            anagramGroups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& kvp : anagramGroups) {
            result.push_back(kvp.second);
        }
        
        return result;
    }
};
