/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) dp[j] = obstacleGrid[0][0] == 0 ? 1 : 0;
                if (obstacleGrid[i - 1][j - 1] == 1) dp[j] = 0;
                else dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

