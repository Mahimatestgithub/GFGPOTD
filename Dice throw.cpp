class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1, vector<int>(x+1, 0));
        dp[0][0]=1;
        for(int p=1; p<=n; p++){
            for(int q=1; q<=x; q++){
                for(int i=1; i<=m; i++){
                    if(q>=i) dp[p][q]+=dp[p-1][q-i];
                }
            }
        }
        return dp[n][x];
    }
};
