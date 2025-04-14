class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // Step 1: Initialize graph
        for (const string &word : words) {
            for (char c : word) {
                graph[c];       // ensures the char exists in the graph
                indegree[c];    // initializes in-degree to 0
            }
        }

        // Step 2: Build graph from word differences
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found = false;

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (graph[w1[j]].insert(w2[j]).second) {
                        indegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix rule violated
            if (!found && w1.length() > w2.length()) return "";
        }

        // Step 3: Topological Sort (BFS)
        queue<char> q;
        for (unordered_map<char, int>::iterator it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0) {
                q.push(it->first);
            }
        }

        string result;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If result size != number of unique chars, graph has a cycle
        if (result.size() != graph.size()) return "";

        return result;
    }
};
