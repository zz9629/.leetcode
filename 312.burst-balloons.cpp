/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int burst(vector<int>& nums, int left, int right, vector<vector<int>>& dp)
    {
        if (left >= right) return 0;
        if (left + 1 == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int res = 0;
        // （left, right）是开区间，首尾不能burst
        for (int mid = left + 1; mid < right; mid++)
        {
            // mid is the last balloon to burst
            // left-right中只剩mid，因此最后分数只与mid, left, right有关
            // 再加上（left-mid）中的得分，以及（mid-right）中的得分
            int temp = burst(nums, left, mid, dp) +
                        burst(nums, mid, right, dp) + 
                        nums[mid] * nums[left] * nums[right];
            res = max(res, temp);
        }
        dp[left][right] = res;
        return res;
    }

    int maxCoins_(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ballons(n + 2, 1);
        for (int i = 0; i < n; i++)
        {
            ballons[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return burst(ballons, 0, ballons.size() - 1, dp);
    }

    int burstBallon(vector<int>& ballons, int left, int right, vector<vector<int>>& dp)
    {
  
    }

    int maxCoins(vector<int>& nums) {
    }

};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {3,1,5,8};
    s.maxCoins(nums);
    return 0;
}