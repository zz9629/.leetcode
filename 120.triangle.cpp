/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int row = triangle.size();
        vector<vector<int>> dp(row + 1, vector<int> (row + 1, INT_MAX - 1));
        dp[0][0] = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= row; j++) { // 注意j的范围，遍历到i即可
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i - 1][j - 1];
            }
        }
        int result = INT_MAX - 1;
        for (int i = 1; i <= row; i++)
        {
            result = min(result, dp[row][i]);
        }
        return result;
    }
};
// @lc code=end

