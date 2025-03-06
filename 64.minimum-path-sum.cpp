/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int minPathSum_(vector<vector<int>>& grid) {

    //     // improved
    //     vector<int> dp(n + 1, INT_MAX);
    //     for (int i = 1; i <= m; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             if (i == 1 && j == 1) dp[j] = grid[i - 1][j - 1];
    //             else dp[j] = grid[i - 1][j - 1] + min(dp[j], dp[j - 1]);
    //         }
    //     }
    //     return dp[n];

    //     // 2-dim
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++) {
    //             if (i == 0 && j == 0) dp[i][j] = 0;
    //             if (i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
    //             if (j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
    //             else
    //             {
    //                 dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
    //     return dp[m - 1][n - 1];

        // 2 
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) dp[i][j] = grid[i - 1][j - 1];
                else dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    // }


    int minPathSum(vector<vector<int>>& grid) {

    }

};
// @lc code=end

