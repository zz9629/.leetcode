/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>

using namespace std;
// @lc code=start
class Solution {
public:
    // std::unordered_map<, class Tp><int, int> areas;

    // bool isInGrid(vector<vector<int> >& grid, int i, int j)
    // {
    //     int m = grid.size(), n = grid[0].size();
    //     if (i < 0 || i >= m || j < 0 || j >= n) {
    //         return false;
    //     }
    //     return true;
    // }

    // int sumOfNeighbors(vector<vector<int> >& grid, int i, int j)
    // {
    //     int m = grid.size(), n = grid[0].size();
    //     set<int> neighbors;
        
    //     vector<int> Dir = {-1, 0, 1, 0, -1};
    //     for (int index = 0; index < Dir.size() - 1; index++)
    //     {
    //         int r = i + Dir[index];
    //         int c = j + Dir[index + 1];
            
    //         if (r < 0 || r >= m || c < 0 || c >= n){
    //             continue;
    //         }
    //         int color = grid[r][c];
    //         neighbors.insert(color);
    //     }

    //     if (neighbors.empty()) return 0;
    //     int sum = 0;
    //     for (const auto & i : neighbors)
    //     {
    //         sum += areas[i];
    //     }
    //     return sum;
    //     // if (vec.size() >= 2) return vec[0] + vec[1];
    //     // return vec[0];
    // }

    // int dfs(vector<vector<int> >& grid, int i, int j, int color)
    // {
    //     int m = grid.size(), n = grid[0].size();
    //     if (i < 0 || i >= m || j < 0 || j >= n) {
    //         return 0;
    //     }
    //     // if (!isInGrid(grid, i, j))

    //     if (grid[i][j] == 1)
    //     {
    //         grid[i][j] = color;
    //         return 1 + 
    //             dfs(grid, i - 1, j, color) + 
    //             dfs(grid, i + 1, j, color) +
    //             dfs(grid, i, j + 1, color) +
    //             dfs(grid, i, j - 1, color);
    //     }
    //     return 0;
    // }

    // int largestIsland_(vector<vector<int>>& grid) {
    //     if (grid.empty() || grid[0].empty()) return 0;

    //     int color = 2;
    //     int result = 0;

    //     // calculate area of an island, and color them.
    //     for (int i = 0; i < grid.size(); i++)
    //     {
    //         for (int j = 0; j < grid[0].size(); j++)
    //         {
    //             if (grid[i][j] == 1)
    //             {
    //                 int area = dfs(grid, i, j, color);   
    //                 areas[color] = area;
    //                 color++;
    //                 result = max(result, area);
    //             }
    //         }
    //     }

    //     // join islands
    //     for (int i = 0; i < grid.size(); i++)
    //     {
    //         for (int j = 0; j < grid[0].size(); j++)
    //         {
    //             if (grid[i][j] == 0)
    //             {
    //                 result = max(result, 1 + sumOfNeighbors(grid, i, j));
    //             }
    //         }
    //     }

    //     return result;
    // }

    int getArea(vector<vector<int> >& grid, int i, int j, int color, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = color;
        vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int sum = 1;
        for (auto dir: directions)
        {
            sum += getArea(grid, i + dir.first, j + dir.second, color, m, n);
        }
        return sum;
    }

    int paintColor(vector<vector<int> >& grid, 
                    std::unordered_map<int, int> areas, 
                    int i, int j, int m, int n)
    {

        unordered_set<int> neighbors;
        vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int sum = 1;
        for (auto dir: directions)
        {
            int row = i + dir.first;
            int col = j + dir.second;
            if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] > 1)
            {
                neighbors.insert(grid[row][col]);
            }
        }

        for (auto neighbor: neighbors)
        {
            sum += areas[neighbor];
        }
        return sum;
    }

    int largestIsland(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int color = 2, result = 0;
        std::unordered_map<int, int> areas;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    auto area = getArea(grid, i, j, color, m, n);
                    areas[color] = area;
                    color++;
                    result = max(result, area);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    auto area = paintColor(grid, areas, i, j, m, n);
                    result = max(result, area);
                }
            }
        }
        return result;
    }

};
// @lc code=end

int main()
{
    vector<vector<vector<int> > > testCases;
    testCases.push_back(vector<vector<int> > ({{1, 0}, {0,1}}));
    testCases.push_back(vector<vector<int> > ({{1, 1}, {0,1}}));
    Solution s;
    for (auto &test : testCases) {
      int area = s.largestIsland(test);
      cout << area << endl;
    }
}

