/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <vector>
// @lc code=start
class Solution {
public:
    /*
    一个负数乘以当前最大值可能变成最小值；一个负数乘以当前最小值可能变成最大值；
    所以，我们需要同时跟踪两个变量：
        maxVal: 以当前元素结尾的连续子数组的最大乘积
        minVal: 以当前元素结尾的连续子数组的最小乘积
    如果当前数是负数，正负号翻转：
        原来的最大乘积 × 负数 → 变成最小乘积；
        原来的最小乘积 × 负数 → 变成最大乘积；
    所以我们需要在乘之前先交换 max 和 min。
    */
    int maxProduct_(vector<int>& nums) {
        int maxVal, minVal, result;
        maxVal = minVal = result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0) swap(maxVal, minVal);

            maxVal = max(nums[i], nums[i] * maxVal);
            minVal = min(nums[i], nums[i] * minVal);
            
            // 因为我们只关心全局的最大乘积，所以只用记录 maxVal 的最大值。
            result = max(result, maxVal);
        }
        return result;
    }

    int maxProduct(vector<int>& nums) {
       
    }

};
// @lc code=end


// nums = [2,3,-2,4]  -> 6
// nums = [-2,0,-1]   -> 0