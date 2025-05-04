#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();
        
        unordered_map<char, int> freq_map;
        int start = 0, min_len = INT_MAX, count = 0;

        for (int end = 0; end < str.size(); ++end) {
            freq_map[str[end]]++;
            
            // Count only when we see a unique character first time
            if (freq_map[str[end]] == 1)
                count++;

            // Shrink the window if it has all unique characters
            while (count == total_unique) {
                min_len = min(min_len, end - start + 1);
                freq_map[str[start]]--;

                if (freq_map[str[start]] == 0)
                    count--;

                start++;
            }
        }

        return min_len;
    }
};
