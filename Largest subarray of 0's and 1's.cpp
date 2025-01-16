
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int ans=0;
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
            cnt--;
            else if(arr[i]==1)
            cnt++;
            if(mp.find(cnt)!=mp.end())
            ans=max(ans,i-mp[cnt]);
            else
            mp[cnt]=i;
        }
        return ans;
    }
};
