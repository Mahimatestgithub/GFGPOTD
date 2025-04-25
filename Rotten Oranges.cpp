class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;
        
        // Step 1: Count fresh oranges and push rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // Step 2: BFS to spread the rot
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cell = q.front(); q.pop();
                int x = cell.first, y = cell.second;
                for (const pair<int, int>& dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            time++;
        }
        
        // Step 3: Check if there are still fresh oranges left
        return fresh == 0 ? time : -1;
    }
};
