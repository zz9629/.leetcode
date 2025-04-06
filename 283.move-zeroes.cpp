/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1) 
        {
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
    }
};
// @lc code=end

