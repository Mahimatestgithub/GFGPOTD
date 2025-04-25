#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        // Store jobs with their profit and deadline
        for (int i = 0; i < n; i++) {
            jobs.push_back(make_pair(profit[i], deadline[i]));
        }
        
        // Sort jobs in descending order of profit
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> parent(maxDeadline + 1);
        
        // Initialize Union-Find parent array
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        
        int count = 0, maxProfit = 0;
        
        for (size_t i = 0; i < jobs.size(); i++) {
            int p = jobs[i].first, d = jobs[i].second;
            int availableSlot = find(d);
            if (availableSlot > 0) {
                parent[availableSlot] = find(availableSlot - 1); // Union
                count++;
                maxProfit += p;
            }
        }
        
        return {count, maxProfit};
    }
};

int main() {
    Solution sol;
    vector<int> deadline = {3, 1, 2, 2};
    vector<int> profit = {50, 10, 20, 30};
    vector<int> result = sol.jobSequencing(deadline, profit);
    cout << "Jobs Done: " << result[0] << ", Max Profit: " << result[1] << endl;
    return 0;
}
