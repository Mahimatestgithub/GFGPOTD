#include <vector>
using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        
        // If sum is odd, partitioning into two equal subsets is impossible
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        int n = arr.size();
        
        // DP array to check if sum 'j' can be formed using any subset
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: A sum of 0 is always possible
        
        for (int num : arr) {
            // Traverse backwards to avoid using the same number multiple times
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};
