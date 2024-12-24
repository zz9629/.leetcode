/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        // int[] dp = new int[n+1];

        // for (int i = 2; i <= n; i++) {
        //     dp[i] = i;
        //     for (int j = i-1; j > 1; j--) {
        //         if (i % j == 0) {
        //             dp[i] = dp[j] + (i/j);
        //             break;
        //         }
                
        //     }
        // }
        // return dp[n];

        vector<int> dp(n + 1, n);
        dp[0] = dp[1] = 0; // initial with 0 is ok
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i; // max value, for prime number
            for (int j = i / 2; j > 1; j--) // start from i / 2;
            {
                if(i % j == 0) {    // can be divided by j
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

