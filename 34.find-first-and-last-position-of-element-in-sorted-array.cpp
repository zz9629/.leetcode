/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty() || target < nums[0] || target > nums[nums.size() - 1]) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) break;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        if (left > right) return {-1, -1};
        // left...right;
        //     mid
        int mid = left + (right - left) / 2;
        // find first in range [left, mid], find last in range [mid, right]
        int first = mid, last = mid;
        int new_right = mid, new_left = mid;  
        while (left <= new_right)
        {
            int mid = left + (new_right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                new_right = mid - 1;
            } else if (nums[mid] < target) left = mid + 1;
        }

        // 
        while (new_left <= right) 
        {
            int mid = new_left + (right - new_left) / 2;
            if (nums[mid] == target) {
                last = mid;
                new_left = mid + 1;
            } else if (nums[mid] > target) right = mid - 1;
        }
        return {first, last};
    }


    std::vector<int> searchRange_(std::vector<int>& nums, int target) {
        int first = -1, last = -1;
        int left = 0, right = nums.size() - 1;
        // 通过最大值最小值快速筛查
        if (nums[left] > target || nums[right] < target) return {-1, -1};

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                first = last = mid;
                break;
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        // 但是仍然可能不存在于数组中
        if (first == -1) return vector<int>{first, last};
        
        // find first
        int r = first;
        while (left <= r)
        {
            int mid = left + (r - left) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                r = mid - 1;
            }
            else left = mid + 1;
        }

        // find last
        int l = last;
        while (l <= right)
        {
            int mid = l + (right - l) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                l = mid + 1;
            }
            else right = mid - 1;
        }
        return vector<int>{first, last};
    }
};
// @lc code=end

