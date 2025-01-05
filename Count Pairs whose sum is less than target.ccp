class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
      // Your code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int c = 0;
        
        while(s<e)
        {
            if(arr[s] + arr[e] < target)
            {
                c += (e-s);
                s++;
            }
            else
            {
                e--;
            }
        }
        return c;
    }
};
