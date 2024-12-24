/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[1][1] = 1;
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (i == 1 && j == 1) continue;
        //         dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        //     }
        // }
        // return dp[m][n];

        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) 
        {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
}