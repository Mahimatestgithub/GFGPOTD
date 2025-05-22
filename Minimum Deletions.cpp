class Solution {
  public:
    int minDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: Single character substrings
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // Fill the table
        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i+1][j-1]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        int lpsLength = dp[0][n-1];
        return n - lpsLength; // Min deletions = total length - LPS length
    }
};
