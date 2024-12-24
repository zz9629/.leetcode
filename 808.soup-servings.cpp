/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double calWeight(int stockA, int stockB, int applyA, int applyB) {
        if (stockA + applyA <= 0 && stockB + applyB > 0) return 1;
        else if (stockA + applyA <= 0 && stockB + applyB <= 0) return 0.5;
        else return 0;
    } 

    double soupServings(int n) {
        int stock = (n + 24) / 25;
        if (stock >= 179) {
            return 1.0;
        }
        if (stock > 5550) return 1;
        vector<vector<double>> dp(stock + 1, vector<double>(stock + 1, 0));
        vector<pair<int, int>> directions = {{-4, 0}, {-3, -1}, {-2, -2}, {-1, -3}};
        for (int i = 0; i <= stock; i++) {
            for (int j = 0; j <= stock; j++) {
                double sum = dp[i][j];
                for(const auto& dir : directions) {
                    int row = i + dir.first;
                    int col = j + dir.second;
                    if (row > 0 && col > 0) {
                        sum += dp[row][col];
                    } else {
                        sum += calWeight(i, j, dir.first, dir.second);
                    }
                }
                dp[i][j] = sum / 4;
            }
        }
        return dp[stock][stock];
    }


    int fun(int n) {
        n = (n + 24) / 25;
        if (n > 168) return 1;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        vector<pair<int, int>> directions = {{-4, 0}, {-3, -1}, {-2, -2}, {-1, -3}};

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                double sum = 0;
                for (const auto& dir: directions) {
                    int row = i + dir.first, col = j + dir.second;
                    if (row > 0 && col > 0) sum += dp[row][col];
                    else if (row <= 0 && col <= 0) sum += 1;
                    else if (row > 0 && col <= 0) sum += 0.5;
                }
                dp[i][j] = sum / 4;
            }
        }
        return dp[n][n];
    }

};
// @lc code=end

int main() {
    Solution s;
    cout << s.soupServings(50) << endl;
}