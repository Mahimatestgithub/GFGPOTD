#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        sort(arr.rbegin(), arr.rend()); // Sort in descending order
        vector<int> ans(arr.begin(), arr.begin() + k); // Take first k elements
        return ans;
    }
};
