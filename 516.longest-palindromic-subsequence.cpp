/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > dp(n, vector<int>(n, 0));

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (s[i] == s[j])
                {
                    if (i - j <= 2) 
                    {
                        dp[j][i] = i - j + 1;
                    }
                    else {
                        dp[j][i] = dp[j + 1][i - 1] + 2;
                    }
                }
                else {
                    dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
                }
                res = max(res, dp[j][i]);
            }
        }
        return res;
    }
};
// @lc code=end

