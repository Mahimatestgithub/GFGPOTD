class Solution {
    public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            if (it != ans.end()) {
                *it = arr[i];
            } else {
                ans.push_back(arr[i]);
            }
        }
        return ans.size();
        
    }
};
