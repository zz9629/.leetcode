/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start

// 二维数组记录容易有边界问题，用递归更好做 
class Solution {
public:

    /* 用递归解决 */
    int helper(vector<int>& nums, int index, int target) {
        if (index < 0 ) return target == 0 ? 1 : 0;
        return helper(nums, index - 1, target + nums[index]) + helper(nums, index - 1, target - nums[index]);
    }

    int findTargetSumWays_(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums.empty()) return 0;
        return helper(nums, n - 1, target);
    }

    /* 转化为01背包 
        https://leetcode.com/problems/target-sum/solutions/97334/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation
    */

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || -sum > target) return 0;
        if ((target + sum) % 2) return 0;
        int goal = (target + sum) / 2;
        int n = nums.size();
        vector<int> dp(goal + 1, 0);
        dp[0] = 1;
        for (const auto& num : nums) {
            for (int j = goal; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[goal];
    }
};
// @lc code=end

