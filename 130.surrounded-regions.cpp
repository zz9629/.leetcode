/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n ) return;
        if (board[row][col] != 'O') return;
        board[row][col] = 'E';
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto & dir: directions) 
        {
            auto i = row + dir.first, j = col + dir.second;
            dfs(board, i , j, m, n); 
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();

        // 类似题目 417. Pacifi Atlantic Water Flow，从四个边往里面走，O->E
        for (int i = 0; i < m; i++) 
        {
            if (board[i][0] == 'O' ) dfs(board, i, 0, m, n);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') dfs(board, 0, j, m, n);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j, m, n);
        }
        // 清理剩下的O为X，把E换回O
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'E') board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end

