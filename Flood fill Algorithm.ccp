class Solution {
  public:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Boundary check
        if (x < 0 || x >= n || y < 0 || y >= m)
            return;
        
        // If the current pixel is not of the original color or already colored, return
        if (image[x][y] != color || image[x][y] == newColor)
            return;
        
        // Change color
        image[x][y] = newColor;
        
        // Visit all 4-directionally connected pixels
        dfs(image, x + 1, y, color, newColor); // down
        dfs(image, x - 1, y, color, newColor); // up
        dfs(image, x, y + 1, color, newColor); // right
        dfs(image, x, y - 1, color, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        
        // Avoid infinite loop when newColor is same as original color
        if (originalColor != newColor) {
            dfs(image, sr, sc, originalColor, newColor);
        }
        
        return image;
    }
};
