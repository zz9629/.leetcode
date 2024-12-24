/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int mod = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        // 递归实现，但是时间复杂度太高，O(k ^ d)
        if (n < 0 || target < 0) return 0;
        if (n == 0) return target == 0 ? 1 : 0;
        int sum = 0;
        for (int i = 1; i <= k && i <= target; i++) {
            sum += numRollsToTarget(n - 1, k, target - i);
        }
        return sum % mod;

        // AC的dp实现，注意初始条件
        if (n == 0) return target == 0 ? 1 : 0;
        if(!n || !k || target <= 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;  // 当扔到最后一个dice, 把target减到0之后，会继续往下dfs(0, 0), 所以应该返回1
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int m = 1; m <= k && m <= j; m++) {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - m] % mod) % mod;
                }
            }
        }
        return dp[n][target];

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 0; j--) {
                for (int face = 1; face <= k && face <= j; face++) {
                    dp[j] += dp[j - face];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.numRollsToTarget(2, 6, 7) << endl;
}