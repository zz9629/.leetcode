
/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
#include "iostream"
#include "vector"
using namespace std;

// @lc code=start
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int left, int right)
    {
        if (nums.empty() || target < nums[left] || target > nums[right]) return false;
        // int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }

    bool search_(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target || 
                nums[left] == target || 
                nums[right] == target) return true;
            if (nums[left] == nums[mid]) left++;
            // left part is sorted
            else if (nums[left] < nums[mid])
            {
                if (nums[left] < target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            // right part is sorted
            else if (nums[left] > nums[mid])
            {
                if (nums[mid] < target && target < nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            // after insert pos
            // else if (nums[mid] <= nums[left] && nums[mid] <= nums[right]) 
            // {
            //     if (binarySearch(nums, target, mid + 1, right)) return true;
            //     right = mid - 1;
            // } 
            // // before insert po
            // else if (nums[mid] > nums[left] && nums[mid] > nums[right] )
            // {
            //     left = mid + 1;
            // }
            // else return binarySearch(nums, target, left, right);
        }

        return false;
    }


    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target || 
                nums[left] == target || 
                nums[right] == target) return true;
            // right is sorted
            if (nums[left] > nums[mid]) {
                if (nums[mid] < target && target < nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            // left is sorted
            else if (nums[mid] > nums[right]) {
                if (nums[left] < target && target < nums[mid]) right = mid - 1;
                else left = mid + 1; 
            }
            else right--;
        }   
        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{2,5,6,0,0,1,2};
    cout << s.search(nums, 3) << endl;
    
    return 0;
}
