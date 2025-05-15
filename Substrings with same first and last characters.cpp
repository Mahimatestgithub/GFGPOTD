class Solution {
public:
    int countSubstring(string &s) {
        int freq[26] = {0};
        
        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            int count = freq[i];
            result += count * (count + 1) / 2;
        }
        
        return result;
    }
};
