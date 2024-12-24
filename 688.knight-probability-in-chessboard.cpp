/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<pair<int, int>> directions = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, 
                                        {1, -2}, {2, -1}, {1, 2}, {2, 1}};
        
    bool isValid(int n, int row, int col) {
        if (row < 0 || col < 0 || row >= n || col >= n) return false;
        return true;
    }

    double knightProbability(int n, int k, int row, int column) {
        if (k < 1) return 1;
        if (n < 3) return 0;
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));

        // not good: 
        /* 注意边界输入，语句 if (n <= 1 || k < 1) return 1; 无法通过以下两个用例
            Input: n = 1, k = 0, row = 0, column = 0
            Output: 1.00000

            Input: n = 1, k = 1, row = 0, column = 0
            Output: 0.00000
        */

        /* 2-dimension doesn't work, since i,j is all over the place.
            vector<vector<double>> memo(n, vector<double>(n, 0));
            int kk = k;
            while(k--) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        double sum = 0;
                        for (const auto dir: directions) {
                            if (isValid(n, i + dir.first, j + dir.second)) {
                                if (k == kk - 1) sum += 1;
                                else sum += memo[i + dir.first][j + dir.second];
                            }
                        }
                        memo[i][j] = sum / 8;
                    }
                }
            }
            return memo[row][column];
        */

        
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        // dp[1] = memo;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         double sum = 0;
        //         for (const auto& dir : directions) {
        //             if (isValid(n, i + dir.first, j + dir.second)) sum += 1;
        //         }
        //         dp[1][i][j] = sum / 8;
        //     }
        // }

        // for (int kk = 1; kk <= k; kk++) {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < n; j++) {
        //             double sum = 0;
        //             for (const auto& dir : directions) {
        //                 if (isValid(n, i + dir.first, j + dir.second)) {
        //                     if (kk == 1) sum += 1;
        //                     else sum += dp[kk - 1][i + dir.first][j + dir.second];
        //                 }
        //             }
        //             dp[kk][i][j] = sum / 8;
        //         }
        //     }
        // }
        // return dp[k][row][column];

        for (int kk = 1; kk <= k; kk++) 
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double sum = 0;
                    for (const auto& dir: directions) {
                        if (isValid(n, i + dir.first, j + dir.second)) {
                            if (kk == 1) sum += 1;
                            else sum += dp[kk - 1][i + dir.first][j + dir.second];
                        }
                    }
                    dp[kk][i][j] = sum / 8;
                }
            }
        }
        return dp[k][row][column];
    }
};
// @lc code=end

