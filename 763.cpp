#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> partitions;
        unordered_map<char, int> lastOccurrence;
        
        // Store the last occurrence index of each character
        for (int i = 0; i < n; i++) {
            lastOccurrence[s[i]] = i;
        }
        
        int start = 0; // start index of the current partition
        int end = 0; // end index of the current partition
        
        for (int i = 0; i < n; i++) {
            end = max(end, lastOccurrence[s[i]]);
            
            // If the current index reaches the end of the current partition
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1; // update the start index for the next partition
            }
        }
        
        return partitions;
    }
};
