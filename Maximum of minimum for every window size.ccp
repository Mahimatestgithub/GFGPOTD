#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;
        
        // Finding Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
        
        // Clear stack for next computation
        while (!s.empty()) s.pop();

        // Finding Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }

        // Step 3: Compute the maximum of minimums for every window size
        vector<int> res(n + 1, INT_MIN);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Step 4: Fill in the gaps from right to left
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        // Return the result from index 1 to n
        return vector<int>(res.begin() + 1, res.end());
    }
};
