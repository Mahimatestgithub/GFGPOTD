class Solution {
  public:
    int findUnique(vector<int> &arr) {
            int ans = arr[0];
        
        for(int i = 1; i < arr.size(); i++)
        {
            ans = ans ^ arr[i];
        }
        return ans;
        // code here
        
    }
};
