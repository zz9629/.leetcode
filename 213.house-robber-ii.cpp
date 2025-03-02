/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums, int left, int right)
    {
        // int pre = 0, cur = 0;
        // for(int i = left; i <= right; i++)
        // {
        //     int temp = cur;
        //     cur = max(pre + nums[i], cur);
        //     pre = temp;
        // }
        // return cur;

        int n = right - left + 1;
        vector<int> dp(n + 1, 0);
        dp[1] = nums[left];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1 + left]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};
// @lc code=end

