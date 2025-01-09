/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS_(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> len(n + 1, 1);
        vector<int> count(n + 1, 1);  // stores count of longest sequence of length lis[i]
        len[0] = 0, len[1] = 1;
        int max_len = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (nums[i - 1] > nums[j - 1]) {
                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if (len[i] == len[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            max_len = max(max_len, len[i]);
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if(len[i] == max_len) result += count[i];
        }
        return result;
    }

    // 没有扩充数组
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        int max_len = 1;                // 初始化为1
        vector<int> dp(N, 1);      // 初始化为1
        vector<int> count(N, 1);   // 初始化为1
        for (int i = 1; i < N; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;    // 新的递增，长度加1
                        count[i] = count[j];  // 个数相等
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        count[i] += count[j]; // 前面有排列组合，加上前面的个数
                    }
                }
            }
            max_len = max(max_len, dp[i]); // 最长的长度
        }

        int result = 0;
        for (int i = 0; i < N; i++)
        {
            if (dp[i] == max_len) result += count[i];
        }
        return result;
    }

};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1 ,3, 5, 4, 7, 7, 8};
    cout <<  s.findNumberOfLIS(nums) << endl;
}
