/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
#include <climits>
class Solution {
public:
    int helper(vector<int>& values, vector<vector<int>>& memo, int left, int right)
    {
        if (left + 1 >= right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int res = INT_MAX;
        for (int mid = left + 1; mid < right; mid++)
        {
            int temp = values[left] * values[right] * values[mid] + 
                    helper(values, memo, left, mid) + 
                    helper(values, memo, mid, right);
            res = min(res, temp);
        }

        memo[left][right] = res;
        return res;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper(values, memo, 0, n - 1);
    }
};
// @lc code=end

