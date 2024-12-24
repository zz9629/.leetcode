/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
#include "vector"
#include <climits>

using namespace std;
// @lc code=start
class Solution {
public:
    int findMin_(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // int minimal = INT_MAX;
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            // minimal = min(minimal, nums[mid]);
            if (nums[mid] < nums[left])
            {
                // minimal = min(minimal, nums[right]);
                right = mid;
            }
            else if (nums[mid] > nums[right]) 
            {
                // minimal = min(minimal, nums[left]);
                left = mid + 1;
            } else right--;
        }
        return nums[left];
    }

    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            // right is sorted
            if (nums[left] > nums[mid]) {
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else right--;
        }
        return nums[left];
    }
    
};
// @lc code=end

