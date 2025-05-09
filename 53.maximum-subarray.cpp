/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// dp[i]：表示以 nums[i] 结尾 的 连续 子数组的最大和。

#include <climits>
#include "vector"
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray_(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = nums[0];
        /*
            vector<int> dp(n, INT_MIN);
            dp[0] = nums[0];
            for (int i = 1; i < n; i++)
            {
                dp[i] = max(nums[i], dp[i - 1] + nums[i]);
                res = max(res, dp[i]);
            }
        */

        int pre = nums[0];
        int cur = INT_MIN;
        for (int i = 1; i < n; i++){
            cur = max(nums[i], pre + nums[i]);
            pre = cur;
            res = max(res, cur);
        }
        
        return res;
    }

    int maxSubArray(vector<int>& nums) {
        // 写出2d以及空间压缩后的1d
        int n = nums.size();
        int pre = nums[0], cur = 0;
        int res = pre;

        for (int i = 1; i < n; i++)
        {
            cur = max(nums[i], nums[i] + pre);
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }

};
// @lc code=end


int main()
{
    vector<int> nums{-1};
    Solution s;
    cout << s.maxSubArray(nums);

    return 0;
}