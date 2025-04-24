#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // because the graph is undirected
        }

        // Step 2: Initialize distance vector with INT_MAX
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap to get the node with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});  // {distance, node}

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};
