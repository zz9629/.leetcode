/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

 #include <climits>
 #include "vector"
 #include <iostream>
 using namespace std;
 
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(), 1);
        int max_len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    Solution s;
    std::cout << s.lengthOfLIS(nums);

    return 0;
}