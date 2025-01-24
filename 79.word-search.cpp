/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include "vector"
#include "string"

using namespace std;
// @lc code=start
class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void backtracing(vector<vector<char> >& board, 
             vector<vector<bool> >& visited, 
             string & word, 
             int row, int col, int level, bool& found)
    {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n ) return;
        if (found || visited[row][col] || board[row][col] != word[level]) return;
        if (level == word.length() - 1) 
        {
            found = true;
            return;
        }
        visited[row][col] = true;
        for (auto & dir: directions) 
        {
            auto i = row + dir.first, j = col + dir.second;
            backtracing(board, visited, word, i, j, level + 1, found);
        }
        visited[row][col] = false;
    }

    bool exist_(vector<vector<char> >& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtracing(board, visited, word, i, j, 0, found);
            }
        }
        // dfs(board, visited, word, 0, 0, 0, found);  
        return found;
    }

    void backtrace(vector<vector<char> >& board)
    {

    }

    bool exist(vector<vector<char> >& board, string word) {

    }

};
// @lc code=end

/*
[["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]]

*/