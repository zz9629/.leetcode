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

    void dfs(vector<vector<int> >& grid, 
            int row, int col, int m, int n, 
            queue<pair<int, int> >& m_queue)
    {
        if (row >= 0 && row < m && col >= 0 && col < n)
        {
            if (grid[row][col] == 0)
            {
                m_queue.push({row, col});
            }
            else if (grid[row][col] == 1)
            {
                grid[row][col] = 2;
                for (auto dir: directions)
                {
                    dfs(grid, row + dir.first, col + dir.second, m, n, m_queue);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int> > m_queue;
        bool found = false;
        for (int i = 0; i < m; i++)
        {
            if (found) break;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    dfs(grid, i, j, m, n, m_queue);
                    found = true;
                    break;
                }
            }
        }
        int level = 0;
        while (!m_queue.empty())
        {
            level++;
            int size = m_queue.size();
            while (size--)
            {
                auto front = m_queue.front();
                m_queue.pop();
                
                for (auto dir: directions)
                {
                    int row = front.first + dir.first;
                    int col = front.second + dir.second;
                    if (row >= 0 && row < m && col >= 0 && col < n)
                    {
                        if (grid[row][col] == 1) return level - 1;
                        else if (grid[row][col] == 2) continue;
                        else if (grid[row][col] == 0){
                            grid[row][col] = 2;
                            m_queue.push({row, col});
                        }
                    }
                }
            }
        }
        return -1;
    }
    void dfs_(vector<vector<int> >& grid, int row, int col, int m, int n, queue<pair<int, int> >& points)
    {
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        if (grid[row][col] == 1)  
        {
            grid[row][col] = 2;
            for (auto dir: directions)
            {
                dfs(grid, row + dir.first, col + dir.second, m, n, points);
            }
        } 
        else if (grid[row][col] == 0)
        {
            points.push({row, col});
        }
    }

    int shortestBridge_(vector<vector<int> >& grid) {
        // find the first island, and change cells as '2', 
        // find 0 neighbors, and put them into a queue
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int> > points; 
        bool found = false;
        for (int i = 0; i < m ; i++)
        {
            if (found) break;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) 
                {
                    dfs_(grid, i, j, m ,n, points);
                    found = true;
                    break;
                }
            }
        }

        int level = 0;
        while (!points.empty()) {
            level++;
            int size = points.size();
            while (size--)
            {
                auto front = points.front();
                points.pop();
                grid[front.first][front.second] = 2;
                for (auto dir: directions)
                {
                    int row = front.first + dir.first;
                    int col = front.second + dir.second;
                    if (row < 0 || row >= m || col < 0 || col >= n) continue;
                    if (grid[row][col] == 1) return level;
                    else if (grid[row][col] == 2) continue;
                    else if (grid[row][col] == 0)
                    {
                        grid[row][col] = 2;
                        points.push({row, col});
                    }
                }
            }
        }
        return level;
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