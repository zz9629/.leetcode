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
    // 1, 2, 3
    // 2, 3, 1
    // 1, 1, 2
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

    int findMin__(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            // right is sorted
            if (nums[left] > nums[mid]) {  // 可能是mid
                right = mid;
            }
            else if (nums[mid] > nums[right]) { // 不可能是mid
                left = mid + 1;
            }
            else right--;
        }
        return nums[left];
    }
    
    int findMin(vector<int>& nums) {
       
    }


};
// @lc code=end

