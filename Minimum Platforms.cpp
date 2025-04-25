
class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0, n = arr.size();

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { // Train arrives before the previous one departs
                platforms++;
                i++;
            } else { // Train departs before the next one arrives
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};
