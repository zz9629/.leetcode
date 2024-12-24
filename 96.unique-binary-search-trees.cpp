/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
   int helper(int n, int left, int right, vector<vector<int>>& memo) {
        if(left > right || left > n || right > n || left < 0 || right < 0) return 1;
        if (left == right) return 1;
        else if (left + 1 == right) return 2;
        if (memo[left][right] != -1) return memo[left][right];
        int result = 0;
        for (int mid = left; mid <= right; mid++) {
            result += helper(n, left, mid - 1, memo) * 
                        helper(n, mid + 1, right, memo);
        }
        memo[left][right] = result;
        return result;
    }

    int numTrees(int n) {
        // method 1: as 1130
        // vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        // int left = 1, right = n;
        // return helper(n, left, right, memo);
        
        // method 2: 
        // https://leetcode.com/problems/unique-binary-search-trees/solutions/31666/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i 
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;      // 注意dp0 = dp1 = 1
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= i; j++) {
                sum += dp[j - 1] * dp[i - j]; // 注意这里是乘的和，左右组合
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};
// @lc code=end

