class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        // First step: move slow by 1 and fast by 2 until they meet
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);

        // Second step: move slow to the start and move both by 1 step
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};
