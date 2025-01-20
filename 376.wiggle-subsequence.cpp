/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <cstdio>
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
        For every position in the array, there are only three possible statuses for it.
            up position, it means nums[i] > nums[i-1]
            down position, it means nums[i] < nums[i-1]
            equals to position, nums[i] == nums[i-1]
        So we can use two arrays up[] and down[] to record 【the max wiggle sequence length】 so far at index i.
        If nums[i] > nums[i-1], that means it wiggles up. the element before it must be a down position. so up[i] = down[i-1] + 1; down[i] keeps the same with before.
        */

        if (nums.size() == 1) return 1;
        int up = 1, down = 1;

        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                up = down + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};
// @lc code=end

