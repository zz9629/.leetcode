/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement_(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            bool greaterThanLeft = mid == 0 || nums[mid] > nums[mid - 1];
            bool greaterThanRight = mid == nums.size() - 1 || nums[mid] > nums[mid + 1];
            if (greaterThanLeft && greaterThanRight) return mid;
            else if (greaterThanLeft)
            {
                left = mid + 1;
            }
            else if (greaterThanRight){
                right = mid - 1;
            }
            else 
            {
                right--;
            }
        }
        return 0;
    }



    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right- left) / 2;
            bool l = mid == 0 || nums[mid] > nums[mid - 1];
            bool r = mid == nums.size() - 1 || nums[mid] > nums[mid + 1];
            if (l && r) return mid;
            // else if (l) left = mid + 1;
            else if (r) right = mid;
            /*
                mid
                  \
                   \
                   mid + 1
            */
            else left = mid + 1;
            /*
                   mid + 1
                    / 
                   /
                mid
            */
        }
        return right; // left equals right
   
    }

};
// @lc code=end

