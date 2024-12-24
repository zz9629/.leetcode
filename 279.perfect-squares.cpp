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
    int numSquares(int n) {
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
};
// @lc code=end

int main()
{
    Solution s;
    auto ans = s.numSquares(12);

    return 0;
}