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
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (const auto& num: nums) {
                if (i >= num) dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

