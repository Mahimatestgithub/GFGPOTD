class Solution {
  public:
    int maxLength(string& str) {
        stack<int> s;
        s.push(-1); // Base index for valid parentheses
        int maxLen = 0;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                s.push(i); // Push the index of '('
            } else {
                s.pop(); // Try to find a matching '('
                
                if (s.empty()) {
                    s.push(i); // If no matching '(', push the index of ')'
                } else {
                    // Calculate the length of the current valid substring
                    maxLen = max(maxLen, i - s.top());
                }
            }
        }
        
        return maxLen;
    }
};
