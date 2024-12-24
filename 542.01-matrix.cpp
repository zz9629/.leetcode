/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix_(vector<vector<int>>& mat) {
        if (mat.empty()) return mat;
        int m = mat.size(), n = mat[0].size();
        // 注意这里是 INT_MAX - 1, 如果是INT_MAX的话，line 23的INT_MAX + 1 会有signed integer overflow问题
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
                else {
                    if (i - 1 >= 0)  {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j - 1 >= 0)  {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + 1 < m) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }

        return dp;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    }
};
// @lc code=end

int main()
{
    vector<vector<int> >  testCases;
    int t = 5;
    while (t--)
        testCases.push_back(vector<int> {0, 1, 0});
    Solution s;
    auto res = s.updateMatrix(testCases);
}
