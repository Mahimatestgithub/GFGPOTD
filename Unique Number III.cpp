
class Solution {
  public:
   int getSingle(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for(const pair<int,int>& it : mp)
            if(it.second == 1)
                return it.first;
        return -1;
    }
};
