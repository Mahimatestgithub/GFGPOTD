#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Step 1: convert all numbers to string
        vector<string> nums;
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back(to_string(arr[i]));
        }
        
        // Step 2: sort using special rule
        sort(nums.begin(), nums.end(), [](string a, string b) {
            return a + b > b + a;  // compare concatenation
        });
        
        // Step 3: if first number is "0", answer is "0"
        if (nums[0] == "0") return "0";
        
        // Step 4: join all numbers
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }
        
        return ans;
    }
};


