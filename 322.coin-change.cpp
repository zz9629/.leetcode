/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 二维
    int coinChange_(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        // 完全背包，物品在内，价值在外正向遍历。
        // dp[i][j] = dp[i - 1][j] + dp[j][j - value];
        for (int i = 1; i <= n; i++)
        {
            int coin = coins[i - 1];
            for (int j = 0; j <= amount; j++)
            {
                if (coin <= j)
                    dp[i][j] = min(dp[i][j - coin] + 1, dp[i - 1][j]);
                else  dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
    }

    // 空间压缩
    int coinChange__(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
        int n = coins.size();

        vector<int> dp (amount + 1, amount + 1);
        for (int i = 1; i <= amount; i++)
        {
            for (const auto& coin : coins)
            {
                if (coin <= i) dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }



    int coinChange(vector<int>& coins, int amount) {
        // 注意dp的初始值
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto & num: coins)
            {
                if (i >= num) dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

};
// @lc code=end

