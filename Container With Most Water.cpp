class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate the width of the container
            int width = right - left;

            // Calculate the height of the container
            int height = min(arr[left], arr[right]);

            // Update the maximum area
            max_area = max(max_area, width * height);

            // Move the pointer pointing to the smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
