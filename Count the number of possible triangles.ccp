 class Solution {
  public:
    int countTriangles(vector<int>& arr) {
    int n = arr.size();
        int cnt = 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n ;j++){
                int sum = arr[i]+arr[j];
                for(int k=j+1;k<n ;k++){
                    if(sum>arr[k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
