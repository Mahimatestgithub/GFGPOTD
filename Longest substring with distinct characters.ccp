#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> last_seen; // To store the last occurrence of each character
        int max_length = 0;                // To store the maximum length of substring
        int start = 0;                     // Start of the current substring

        for (int end = 0; end < s.size(); ++end) {
            char current_char = s[end];
            
            // If the character is already in the map and within the current window
            if (last_seen.find(current_char) != last_seen.end() && last_seen[current_char] >= start) {
                start = last_seen[current_char] + 1; // Move the start forward
            }
            
            last_seen[current_char] = end; // Update the last occurrence of the character
            max_length = max(max_length, end - start + 1); // Update the maximum length
        }

        return max_length;
    }
};
