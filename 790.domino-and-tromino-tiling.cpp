/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        int mod = 1000000000 + 7;
        if (n <= 2) return n;
        vector<unsigned int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};
// @lc code=end

