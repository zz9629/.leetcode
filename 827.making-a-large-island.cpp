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
    vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int getArea(vector<vector<int> >& grid, int i, int j, int color, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = color;
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

