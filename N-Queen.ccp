class Solution {
  public:
    vector<vector<int>> res;
    
    bool isSafe(vector<int>& board, int row, int col) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col))
                return false;
        }
        return true;
    }

    void solve(int col, vector<int>& board, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 1; row <= n; row++) {
            if (isSafe(board, row, col)) {
                board[col] = row;
                solve(col + 1, board, n);
                board[col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0);
        solve(0, board, n);
        return res;
    }
};
