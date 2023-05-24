class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n+1);
        for (int i = 0; i < n; i++) {
            prefixXOR[i+1] = prefixXOR[i] ^ arr[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    int a = prefixXOR[j] ^ prefixXOR[i];
                    int b = prefixXOR[k+1] ^ prefixXOR[j];
                    if (a == b) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
