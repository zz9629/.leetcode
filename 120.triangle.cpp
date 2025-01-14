/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotal_(vector<vector<int> >& triangle) {
        if (triangle.empty()) return 0;
        int row = triangle.size();
        vector<vector<int> > dp(row + 1, vector<int>(row + 1, INT_MAX));
        dp[0][0] = 0;
        int res = INT_MAX;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= i; j++) // 注意j的范围，遍历到i即可
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i -1][j]) + triangle[i - 1][j - 1];
                
                if (i == row) res = min(res, dp[i][j]);
            }

        }
        return res;
    }

    int minimumTotal(vector<vector<int> >& triangle) {
    
    }
};
// @lc code=end

