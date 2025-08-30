class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = n - 1;

        // Step 1: Find potential celebrity
        while (i < j) {
            if (mat[i][j] == 1) {
                // i knows j -> i not celebrity
                i++;
            } else {
                // i doesn't know j -> j not celebrity
                j--;
            }
        }

        int cand = i;

        // Step 2: Verify candidate
        for (int k = 0; k < n; k++) {
            if (k == cand) continue;
            // cand should not know k, and everyone should know cand
            if (mat[cand][k] == 1 || mat[k][cand] == 0) {
                return -1;
            }
        }

        return cand;
    }
};
