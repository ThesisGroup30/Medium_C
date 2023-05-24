#include <vector>
#include <cmath>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Check if the element at mid is closer to x or its right neighbor
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        vector<int> result(arr.begin() + left, arr.begin() + left + k);
        return result;
    }
};
