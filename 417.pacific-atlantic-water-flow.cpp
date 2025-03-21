/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int> >& heights, vector<vector<bool> >& canVisit, int row, int col)
    {
        if (heights.empty() || heights[0].empty()) return;
        int m = heights.size(), n = heights[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        // 终止条件
        if (canVisit[row][col]) return;
        canVisit[row][col] = true;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto & dir: directions) 
        {
            auto i = row + dir.first, j = col + dir.second;
            if (i >= 0 && i < m && j >= 0 && j < n &&
                heights[i][j] >= heights[row][col]) 
                {
                    dfs(heights, canVisit, i, j);
                }
        }

    }

    vector<vector<int> > pacificAtlantic_(vector<vector<int> >& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool> > canPacific(m, vector<bool>(n, false)); 
        vector<vector<bool> > canAtlantic(m, vector<bool>(n, false)); 
        for (int i = 0; i < m; i++) 
        {
            dfs(heights, canPacific, i, 0);
            dfs(heights, canAtlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, canPacific, 0, j);
            dfs(heights, canAtlantic, m - 1, j);
        }
        vector<vector<int> > result;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (canPacific[i][j] && canAtlantic[i][j])
                {
                    result.push_back(vector<int>{i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int> >& heights, vector<vector<bool> >& ocean, int m, int n, int row, int col)
    {
    }

    vector<vector<int> > pacificAtlantic(vector<vector<int> >& heights) {
    }

};
// @lc code=end

