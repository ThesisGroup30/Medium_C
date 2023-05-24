#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    string frequencySort(string s) {
        // Create a frequency map to count the occurrences of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Sort the characters based on their frequencies in decreasing order
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freqMap[a] != freqMap[b]) {
                return freqMap[a] > freqMap[b];
            }
            return a < b;
        });
        
        // Return the sorted string
        return s;
    }
};
