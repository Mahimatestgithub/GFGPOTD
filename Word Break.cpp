#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size(), m = dictionary.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int k = 0;
                for (int l = i; l < n && k < dictionary[j].size(); l++) {
                    if (s[l] == dictionary[j][k]) {
                        k++;
                    } else {
                        break;
                    }
                }
                if (k == dictionary[j].size()) {
                    dp[i] |= dp[i + k];
                }
            }
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    string s = "ilikegfg";
    vector<string> dictionary = {"i", "like", "man", "india", "gfg"};
    cout << (sol.wordBreak(s, dictionary) ? "true" : "false") << endl;
    return 0;
}
