#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();

        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        int maxVal = INT_MIN;
        for (int i = 0; i < k; ++i) {
            minHeap.push(make_tuple(arr[i][0], i, 0));
            maxVal = max(maxVal, arr[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            T t = minHeap.top();
            minHeap.pop();
            int minVal = get<0>(t);
            int row = get<1>(t);
            int idx = get<2>(t);

            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            if (idx + 1 == n) break;

            int nextVal = arr[row][idx + 1];
            minHeap.push(make_tuple(nextVal, row, idx + 1));
            maxVal = max(maxVal, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};
