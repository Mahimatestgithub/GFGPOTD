class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
       unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        
        
        for(auto& str:arr) {
             string sorted =str;
             
             sort(sorted.begin(),sorted.end());
             mp[sorted].push_back(str);
        }
        
        for(auto it:mp) {
             ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
            

        }
};
