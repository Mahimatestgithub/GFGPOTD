class Solution {
  public:
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;
        
        // Add current node to path
        path.push_back(node->data);

        // Check if it's a leaf node
        if (!node->left && !node->right) {
            result.push_back(path); // Save the path
        } else {
            // Continue DFS for left and right subtree
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
};
