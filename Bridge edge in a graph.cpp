class Solution {
  public:
    int timer;
    vector<int> tin, low;
    vector<bool> visited;
    bool bridgeFound;

    void dfs(int node, int parent, vector<int> adj[], int c, int d) {
        visited[node] = true;
        tin[node] = low[node] = timer++;
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            
            if (!visited[neighbor]) {
                dfs(neighbor, node, adj, c, d);
                low[node] = min(low[node], low[neighbor]);

                // Check for bridge
                if (low[neighbor] > tin[node]) {
                    // This edge is a bridge
                    if ((node == c && neighbor == d) || (node == d && neighbor == c)) {
                        bridgeFound = true;
                    }
                }
            } else {
                // Back edge
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        bridgeFound = false;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, c, d);
            }
        }

        return bridgeFound;
    }
};
