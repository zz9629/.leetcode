/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int> >& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        if (grid[i][j] == 1)
        {
            grid[i][j] = 2;
            return 1 + 
                dfs(grid, i - 1, j) + 
                dfs(grid, i + 1, j) +
                dfs(grid, i, j + 1) +
                dfs(grid, i, j - 1);
        }
        return 0;
    }

    // dfs递归
    int maxAreaOfIsland_(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j);
                    result = max(result, area);
                }
            }
        }

        return result;
    }
    bool valid(int m, int n, int i, int j) {
        if (i >= 0 && j >= 0 && i < m && j < n) return true;
        else return false;
    }
    // 非递归
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        stack<pair<int, int> > buffer;
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 1;
                    grid[i][j] = 2;
                    buffer.push(pair<int, int>(i, j));
                    while (!buffer.empty())
                    {
                        auto top = buffer.top();
                        buffer.pop();
                        for (const auto& dir: directions)
                        {
                            int row = top.first + dir.first;
                            int col = top.second + dir.second;
                            if (row >= 0 && row < m && col >= 0 && col < n && 
                                grid[row][col] == 1) // 确保为1，否则会死循环
                            {
                                // 入栈的时候记面积，避免重复入栈
                                buffer.push(pair<int, int>(row, col));
                                grid[row][col] = 2;
                                area++;
                            }
                        }
                    }
                    result = max(result, area);
                }
            }
        }
        return result;
    }

};
// @lc code=end

