/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// 需要建立一颗二叉树，使所有node总和最小，然后返回总和最大的路径。
// @lc code=start
#include <climits>
class Solution {
public:
    int helper(int left, int right, vector<vector<int>>& memo)
    {
        if (left == right) return 0;
        if (left == right - 1) return  left;
        if (memo[left][right] != -1) return memo[left][right];

        int result = INT_MAX;
        for (int mid = left + 1; mid < right; mid++)
        {   
            int temp = mid + max(helper(left, mid - 1, memo), helper(mid + 1, right, memo));
            result = min(result, temp);
        }
        memo[left][right] = result;
        return result;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return helper(1, n, memo);
    }

};
// @lc code=end

