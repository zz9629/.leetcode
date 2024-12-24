/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};
// @lc code=end

