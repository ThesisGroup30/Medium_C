class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        int n = s1.length();
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        
        // count frequencies of each character in s1 and s2
        for (int i = 0; i < n; i++) {
            freq1[s1.charAt(i) - 'a']++;
            freq2[s2.charAt(i) - 'a']++;
        }
        
        // check if s1 can break s2
        int count1 = 0, count2 = 0;
        for (int i = 0; i < 26; i++) {
            count1 += freq1[i];
            count2 += freq2[i];
            if (count1 < count2) {
                return false;
            }
        }
        
        // check if s2 can break s1
        count1 = 0;
        count2 = 0;
        for (int i = 25; i >= 0; i--) {
            count1 += freq1[i];
            count2 += freq2[i];
            if (count1 < count2) {
                return false;
            }
        }
        
        return true;
    }
}
