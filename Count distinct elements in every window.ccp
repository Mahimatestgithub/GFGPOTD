#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result; // To store the result
        unordered_map<int, int> freqMap; // Hash map to store frequencies of elements

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }

        // Add the count of distinct elements in the first window
        result.push_back(freqMap.size());

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            // Remove the element going out of the window
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]);
            }

            // Add the new element in the current window
            freqMap[arr[i]]++;

            // Add the count of distinct elements in the current window
            result.push_back(freqMap.size());
        }

        return result;
    }
};
