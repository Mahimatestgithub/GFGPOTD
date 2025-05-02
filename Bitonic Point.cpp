// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[mid + 1]) {
                // We are in the decreasing part; max is at mid or to the left
                right = mid;
            } else {
                // We are in the increasing part; max is to the right
                left = mid + 1;
            }
        }
        
        // At this point, left == right and points to the maximum element
        return arr[left];
    }
};
