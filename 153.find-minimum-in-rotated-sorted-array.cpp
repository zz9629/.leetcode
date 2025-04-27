/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // right is sorted
            if (nums[mid] < nums[left])
            {
                right = mid;
            }
            // left is sorted
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else {
                right--;
            }
        }

        return nums[left]; 
    }
};
// @lc code=end

