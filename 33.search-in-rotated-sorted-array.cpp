/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            // [left, .... mid, ... right]
            auto mid = left + (right - left) / 2;

            if (target == nums[left]) return left;
            else if (target == nums[mid]) return mid; 
            else if (target == nums[right]) return right;

            // left part is sorted
            if (nums[mid] > nums[right])
            {
                if (nums[left] < target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            // right part is sorted
            else if (nums[mid] < nums[left])
            {
                if (nums[mid] < target && target < nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else right--;
        }
        return -1;
    }
};
// @lc code=end

