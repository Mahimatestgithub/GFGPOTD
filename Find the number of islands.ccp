class Solution {
  public:
    int n, m;

    // DFS to mark visited land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 'L')
            return;

        // Mark current cell as visited
        grid[i][j] = '$';

        // Explore all 8 directions
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0)
                    dfs(grid, i + dx, j + dy);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
