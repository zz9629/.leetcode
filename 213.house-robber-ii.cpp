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
        int pre = 0, cur = 0;
        for(int i = left; i <= right; i++)
        {
            int temp = cur;
            cur = max(pre + nums[i], cur);
            pre = temp;
        }
        return cur;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};
// @lc code=end

