class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // Step 1: Find in-degrees
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }
        
        // Step 2: Push nodes with in-degree 0 to queue
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        
        // Step 3: Process queue
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // If topo has all nodes, it's valid
        if (topo.size() == V)
            return topo;
        else
            return {}; // Not a DAG (cycle exists)
    }
};
