class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        int cur = 0;
        int cnt = 0;
        for(int n:arr)
        {
            cur ^= n;
            cnt += cur==k;
            cnt += mp[cur^k];
            mp[cur]++;
        }
        return cnt;
    }
};
