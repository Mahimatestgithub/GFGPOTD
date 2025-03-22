class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        
        // Compute max for two cases: exclude first house or exclude last house
        return max(robLinear(arr, 0, n - 2), robLinear(arr, 1, n - 1));
    }
};
