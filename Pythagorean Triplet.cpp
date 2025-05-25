class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> squares;
        
        // Store all squares in a set
        for(int i = 0; i < n; i++) {
            squares.insert(arr[i] * arr[i]);
        }

        // Check all unique pairs (a, b)
        for(int i = 0; i < n; i++) {
            int a2 = arr[i] * arr[i];
            for(int j = i + 1; j < n; j++) {
                int b2 = arr[j] * arr[j];
                int sum = a2 + b2;
                if(squares.find(sum) != squares.end()) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
