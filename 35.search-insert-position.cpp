/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <vector>
// @lc code=start
class Solution {
public:
    int v1(std::vector<int>& nums, int target)
    {
        int pos = 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
                pos = left;
            }
            else if (nums[mid] >= target) right = mid - 1;
        }
        return pos;
    }


    int searchInsert_(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int pos = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) 
            {
                left = mid + 1;
                pos = left;
            }
            else right = mid - 1;
        }
        return pos;
    }

    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.empty() || target <= nums[0]) return 0;
        if (target > nums[nums.size() - 1]) return nums.size();
        int pos = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] >= target) right = mid - 1;
            else if (nums[mid] < target) 
            {
                pos = mid + 1;
                left = mid + 1;
            }
        }
        return pos;
    }
};
// @lc code=end

