class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, recStack)) return true;
            } else if (recStack[neighbor]) {
                // Found a node that is in current path => cycle detected
                return true;
            }
        }

        recStack[node] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Check for cycle in each component
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack)) return true;
            }
        }

        return false;
    }
};
