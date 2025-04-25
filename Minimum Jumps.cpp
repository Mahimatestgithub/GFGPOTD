class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // If array has only one element, no jumps are needed
        if (n == 1) return 0;
        
        // If the first element is 0, we cannot move anywhere
        if (arr[0] == 0) return -1;
        
        // Initialize variables
        int maxReach = arr[0];  // the maximum index we can reach
        int steps = arr[0];     // the number of steps we can take within the current jump
        int jumps = 1;          // at least one jump is needed
        
        // Traverse the array from the second element to the end
        for (int i = 1; i < n; i++) {
            // If we have reached the last element
            if (i == n - 1) return jumps;
            
            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);
            
            // Use a step to move to the next element
            steps--;
            
            // If no steps are remaining
            if (steps == 0) {
                // We must take a jump
                jumps++;
                
                // If the current index is greater than maxReach, we cannot move further
                if (i >= maxReach) return -1;
                
                // Reinitialize the steps to the number of steps we can take from the new range
                steps = maxReach - i;
            }
        }
        
        return -1;  // If we exit the loop without reaching the end
    }
};
