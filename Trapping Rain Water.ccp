#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // At least 3 blocks are needed to trap water.

        int left = 0, right = n - 1; // Two pointers
        int leftMax = 0, rightMax = 0; // Maximum height from left and right
        int water = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left]; // Update left maximum
                } else {
                    water += leftMax - arr[left]; // Water trapped at current position
                }
                left++; // Move left pointer
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right]; // Update right maximum
                } else {
                    water += rightMax - arr[right]; // Water trapped at current position
                }
                right--; // Move right pointer
            }
        }

        return water;
    }
};
