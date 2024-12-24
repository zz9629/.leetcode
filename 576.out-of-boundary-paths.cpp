/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
    bool isOut(int m, int n, int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n) return false;
        return true;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1000000000 + 7;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        vector<pair<int, int>> directions = {{-1, 0},  {1, 0}, {0, -1}, {0, 1}};
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++) {
                    int sum = 0;
                    for (const auto& dir: directions) {
                        int row = i + dir.first, col = j + dir.second;
                        if (isOut(m, n, row, col)) sum = (sum + 1) % mod;
                        else sum = (sum + dp[k - 1][row][col]) % mod;
                    }
                    dp[k][i][j] = sum;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};
// @lc code=end

