#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int editDistance(std::string str1, std::string str2) {
        int m = str1.length();
        int n = str2.length();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
        
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};
