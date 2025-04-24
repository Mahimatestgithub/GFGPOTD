class Solution {
  public:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size()) return true; // Word found
        
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[index]) {
            return false;
        }
        
        char temp = mat[i][j];
        mat[i][j] = '#'; // Mark as visited
        
        int dX[] = {-1, 1, 0, 0}; // Possible moves (up, down, left, right)
        int dY[] = {0, 0, -1, 1};
        
        for (int d = 0; d < 4; d++) {
            if (dfs(mat, word, i + dX[d], j + dY[d], index + 1)) {
                return true;
            }
        }
        
        mat[i][j] = temp; // Restore original character
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
