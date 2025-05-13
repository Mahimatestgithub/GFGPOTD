#include <iostream>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        if (r > n - r)
            r = n - r;

        long long res = 1;  // use long long for intermediate values
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }

        return (int)res;  // final result fits in 32-bit, cast back to int
    }
};
