/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// 注意比较
// 1143. Longest Common Subsequence LSC，这是求最大值，所以初始化为0即可
// 712. Minimum ASCII Delete Sum for Two Strings 注意初始化；
// 72. Edit Distance 注意初始化

// @lc code=start
#include <climits>
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // m + n
        // dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                                    //replace       //delete        //insert
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

