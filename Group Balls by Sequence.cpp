#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        if (arr.size() % k != 0)
            return false;

        map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;  // smallest available number

            for (int i = 0; i < k; i++) {
                int current = start + i;

                // If the current number doesn't exist or has zero count
                if (freq.find(current) == freq.end())
                    return false;

                freq[current]--;

                // Remove it if count becomes zero
                if (freq[current] == 0)
                    freq.erase(current);
            }
        }

        return true;
    }
};
