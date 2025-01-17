#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1);
        
        // Step 1: Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= arr[i];
        }
        
        // Step 2: Compute suffix products and combine
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= arr[i];
        }
        
        return ans;
    }
};
