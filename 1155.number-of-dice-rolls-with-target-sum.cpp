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

    int numRollsToTarget_recursive(int n, int k, int target) {
          // 递归实现，但是时间复杂度太高，O(k ^ d)
          if (n < 0 || target < 0) return 0;
          if (n == 0) return target == 0 ? 1 : 0;
          int sum = 0;
          for (int i = 1; i <= k && i <= target; i++) {
              sum += numRollsToTarget_recursive(n - 1, k, target - i);
          }
          return sum % mod;
    }

    int numRollsToTarget_2dim(int n, int k, int target) {
        // AC的dp实现，注意初始条件
        if (n == 0) return target == 0 ? 1 : 0;
        if(!n || !k || target <= 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;  // 当扔到最后一个dice, 把target减到0之后，会继续往下dfs(0, 0), 所以应该返回1
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // int ans = 0; // 这里相当于省略了一个初始化
                for (int m = 1; m <= k && m <= j; m++) {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - m] % mod) % mod;
                    // ans = ans + dp[i - 1][j - m];
                }
                // dp[i][j] = ans;
            }
        }
        return dp[n][target];
    }

    // 二维已经算空间优化了。
    int numRollsToTarget_1dim(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 0; j--) {
                int way = 0; // 这里需要初始化
                for (int face = 1; face <= k && face <= j; face++) {
                    way = (way + dp[j - face]) % mod;
                }
                dp[j] = way;
                
            }
        }
        return dp[target];
    }

    int numRollsToTarget(int n, int k, int target) {

        // return numRollsToTarget_1dim(n, k, target);
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.numRollsToTarget(2, 6, 7) << endl;
}