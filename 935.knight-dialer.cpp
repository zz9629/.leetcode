/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int mod = 1000000000 + 7;
    vector<pair<int, int>> directions = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1},
                                        {1, -2}, {2, -1}, {1, 2}, {2, 1}};
    int rows = 4, cols = 3;

    bool valid(int row, int col) {
        if (row >= 0 && row < rows - 1 && col >= 0 && col < rows - 1) return true;
        if (row == rows - 1 && col == 1) return true;
        return false;
    }

    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(rows, vector<int>(cols, 0)));
        
        int res = 0;
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    // ！这里要判断合法性，否则无意义
                    if (!valid(i, j)) continue;
                    int sum = 0;
                    // 初始条件的处理
                    if (k == 1) {
                        sum += 1;
                    }
                    else {
                        for (const auto& dir : directions) {
                            int row = i + dir.first;
                            int col = j + dir.second;
                            if (valid(row, col)) sum = (sum + dp[k - 1][row][col]) % mod;
                        }
                    }
                    // 最后把sum给此单元格
                    dp[k][i][j] = sum;
                    if (k == n) res = (res + sum) % mod;;
                }
            }
        }
        return res;
    }


    class Solution {
public:
    int rows = 4, cols = 3;

    bool valid(int i, int j) {
        if (i >= 0 && i < 3 && j >= 0 && j < 3) return true;
        if (i == 3 && j == 1) return true;
        return false;
    }

    int knightDialer(int n) {
        int mod = 1000000000 + 7;
        vector<pair<int, int>> directions = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1},
                                            {1, -2}, {2, -1}, {1, 2}, {2, 1}};
        vector<vector<vector<int>> > dp(n + 1, vector<vector<int>>(rows, vector<int>(cols, 0)));
        
        int res = 0;
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int sum = 0;
                    if (!valid(i, j)) continue;
                    {
                        if (k == 1) sum += 1;
                        else {
                            for (const auto& dir: directions) {
                                if (valid(i + dir.first, j + dir.second)) {
                                    sum = (sum + dp[k - 1][i + dir.first][j + dir.second]) % mod;
                                }
                            }
                        }
                    }
                    dp[k][i][j] = sum;
                    if (k == n) res = (res + sum) % mod;
                }
            }
        }
        return res;
    }
};

};
// @lc code=end

