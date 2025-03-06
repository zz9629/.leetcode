/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include <numeric>
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition_(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 1; i <= n; i++) {
            int value = nums[i - 1];
            for (int j = 0; j <= target; j++) {
                if (target < value) dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - value];
                }
            }
        }
        return dp[n][target];
    }


    bool canPartition__(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto& num: nums)
        {
            for (int j = target; j >= 0; j--)
            {
                if (j >= num) dp[j] = dp[j - num] || dp[j];
            }
        }
        return dp[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        sum /= 2;
        // 0 1 背包
        vector<int> dp(sum + 1, false);
        dp[0] = true;
        for (auto & num: nums)
        {
            for (int i = sum; i >= num; i--)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[sum];
    }


};
// @lc code=end

