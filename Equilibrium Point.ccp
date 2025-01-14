class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int totalSum = 0;
        int leftSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
        }
        for (int i = 0; i < arr.size(); i++) {
            totalSum -= arr[i];
            if (leftSum == totalSum) {
                return i; // Use 0-based index
            }
            leftSum += arr[i];
        }
        return -1; // Return -1 if no equilibrium point is found
    }
};
