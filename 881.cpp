#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        
        int left = 0; // left pointer
        int right = n - 1; // right pointer
        int boats = 0; // number of boats
        
        while (left <= right) {
            // Check if the heaviest person and the lightest person can be accommodated in the same boat
            if (people[left] + people[right] <= limit) {
                left++; // move the left pointer to the next person
            }
            right--; // move the right pointer to the next person
            boats++; // increment the number of boats used
        }
        
        return boats;
    }
};
