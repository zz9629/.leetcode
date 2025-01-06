/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <vector>
using namespace std;

// @lc code=start
#include <cmath>
class Solution {
public:
    // 完全背包，价值在外正向，物品在内
    // 二维
    int numSquares_(int n) {
        int num = sqrt(n);
        vector<vector<int> > dp(num + 1, vector<int> (n + 1, n + 1));
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i * i <= j; i++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
            }
        }
        return dp[num][n];
    }

    // 压缩到一维
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0, dp[1] = 1;

        for (int i = 1; i <= n; i++)
        {
            // 注意控制j的范围 j * j <= i
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }


};

// @lc code=end

int main()
{
    Solution s;
    auto ans = s.numSquares(12);

    return 0;
}