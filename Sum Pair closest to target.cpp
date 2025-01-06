#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // Handle edge case
        if (arr.size() < 2) return {};

        // Sort the array
        sort(arr.begin(), arr.end());

        // Initialize pointers and variables to track result
        int left = 0, right = arr.size() - 1;
        int closestDiff = INT_MAX;  // Minimum difference with target
        vector<int> result;

        while (left < right) {
            int sum = arr[left] + arr[right];
            int diff = abs(target - sum);

            // Check if the current pair is closer or satisfies conditions
            if (diff < closestDiff || 
                (diff == closestDiff && (arr[right] - arr[left] > result[1] - result[0]))) {
                closestDiff = diff;
                result = {arr[left], arr[right]};
            }

            // Move pointers based on the comparison with target
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
