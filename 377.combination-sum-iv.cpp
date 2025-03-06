/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        // 注意是unsigned int: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'value_type' (aka 'int') (solution.cpp
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // 完全背包，价值在外正向遍历
        // dp[i][j] = 不拿dp[i - 1][j] + 拿dp[i][j - weight]
        for (int i = 1; i <= target; i++) {
            for (const auto& num: nums) {
                if (i >= num) dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }



    int combinationSum4(vector<int>& nums, int target) {
    
    }
};
// @lc code=end

