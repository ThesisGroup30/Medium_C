#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        std::sort(grades.begin(), grades.end(), std::greater<int>());  // Sort grades in non-increasing order
        
        int groups = 1;  // At least one group can be formed
        int sum = grades[0];  // Sum of grades in the current group
        int totalStudents = 1;  // Total number of students in the current group
        
        for (int i = 1; i < n; i++) {
            sum += grades[i];
            totalStudents++;
            
            if (sum >= totalStudents * (totalStudents + 1) / 2) {
                groups++;  // Create a new group
                sum = grades[i];
                totalStudents = 1;
            }
        }
        
        return groups;
    }
};
