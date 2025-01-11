/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& values, vector<vector<int>>& memo, int left, int right)
    {
        if (left + 1 == right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int result = INT_MAX;
        for (int mid = left + 1; mid < right; mid++)
        {
            result = min(result, values[left] * values[mid] * values[right] + 
                    helper(values, memo, left, mid) + 
                    helper(values, memo, mid, right));
        }
        memo[left][right] = result;
        return result;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper(values, memo, 0, n - 1);
    }
};
// @lc code=end

