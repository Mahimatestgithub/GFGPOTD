class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true; // Mark the node as visited
        result.push_back(node); // Add it to the result
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;
        
        // Start DFS from node 0
        dfsUtil(0, adj, visited, result);
        
        return result;
    }
};
