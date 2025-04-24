class Solution {
  public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == -1) return node;
        return parent[node] = findParent(parent[node], parent); // Path compression
    }

    void unionSet(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V, -1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu == pv) {
                return true;  // Cycle detected
            } else {
                unionSet(u, v, parent);
            }
        }

        return false;  // No cycle
    }
};
