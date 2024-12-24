/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate_(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (mid - 1 < 0 || mid + 1 >= nums.size()) return -1;
            if (nums[mid] != nums[mid -1] && nums[mid] != nums[mid + 1]) return nums[mid];
            if (mid % 2) mid -= 1;
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            else right = mid;
        }
        return nums[left];
    }

    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (mid-1 < 0 || mid + 1 >= nums.size()) return -1;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid + 1]) return nums[mid];
            if (mid % 2) mid--;
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            else right = mid;
        }

        return nums[right];
    }
};
// @lc code=end

