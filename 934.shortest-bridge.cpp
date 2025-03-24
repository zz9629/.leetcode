/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int> >& grid, int m, int n, int i, int j,
             queue<pair<int, int>> & points)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] == 2) return;
        if (grid[i][j] == 0)
        {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        for (auto & dir: directions)
        {
            dfs(grid, m, n,i + dir.first, j + dir.second,points);
        }
    }

    int shortestBridge_(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        bool found = false;

        queue<pair<int, int>> points;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, m, n, i, j, points);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int level = 0;
        while (!points.empty())
        {
            level++;
            int len = points.size();
            while (len--)
            {
                auto front = points.front();
                points.pop();
                // 直接找neighbors
                for (auto & dir: directions)
                {
                    int row = front.first + dir.first;
                    int col = front.second + dir.second;
                    // 注意判断合法性
                    if (row < 0 || row >= m || col < 0 || col >= n) continue;
                    if (grid[row][col] == 1)
                    {
                        return level;
                    }
                    else if (grid[row][col] == 2)
                    {
                        continue;
                    }
                    else 
                    {
                        grid[row][col] = 2;
                        points.push({row, col});
                    }
                }
                
            }
        }
        return level;
    }


    int shortestBridge(vector<vector<int> >& grid) {
        return 0;
    }

};
// @lc code=end

int main()
{
    vector<vector<vector<int> > > testCases;
    testCases.push_back(vector<vector<int> > ({{0, 1}, {1,0}}));
    testCases.push_back(vector<vector<int> > ({{1, 1}, {0,1}}));
    Solution s;
    for (auto &test : testCases) {
      int area = s.shortestBridge(test);
      cout << area << endl;
    }
}