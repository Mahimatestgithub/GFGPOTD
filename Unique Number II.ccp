class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
            unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto &i:mp){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
