// User function template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1, cnt = 0;

        // Step 1: Find the candidate for the majority element
        for (int i = 0; i < arr.size(); i++) {
            if (cnt == 0) {
                candidate = arr[i];
                cnt = 1;
            } else if (arr[i] == candidate) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Step 2: Verify if the candidate is a majority element
        cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == candidate) {
                cnt++;
            }
        }

        if (cnt > arr.size() / 2) {
            return candidate;
        }
        return -1;
    }
};
