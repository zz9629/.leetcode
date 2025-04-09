/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    // recursive
    int helper(int n, vector<int>& dp)
    {
        if (dp[n]) return dp[n];
        int result = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            auto l = max(i, helper(i, dp));
            auto r = max(n - i, helper(n - i, dp));
            result = max(l * r, result);
        }
        dp[n] = result;
        return result;
    }
    int integerBreak__recursive(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        return helper(n, dp);
    }   

    // good 
    int integerBreak_(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                auto temp = max(j, dp[j]) * max(i - j, dp[i - j]);
                dp[i] = max(dp[i], temp);
            }
        }
        return dp[n];
    }


    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }

};
// @lc code=end

