/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX - 1));
        // for (int i = 0; i <= m; i++) dp[i][0] = 0;
        // for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + mat[i - 1][j - 1];
            }
        }

        // if (matrix.empty()) return 0;
        // int m = matrix.size(), n = matrix[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        // for (int i = 0; i < n; i++) dp[0][i] = matrix[0][i];
        // for (int i = 1; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         int temp = dp[i - 1][j];
        //         if (j > 0) temp = min(temp, dp[i - 1][j - 1]) ;
        //         if (j < n - 1) temp = min(temp, dp[i - 1][j + 1]);
        //         dp[i][j] = temp + matrix[i][j];
        //     }
        // }

        // int sum = dp[m - 1][0];
        // for (int i = 0; i < n; i++) sum = min(sum, dp[m - 1][i]);
        // return sum;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{-84,-36,2}, {87,-79,10}, {42,10,63}};
    s.minFallingPathSum(matrix);
}