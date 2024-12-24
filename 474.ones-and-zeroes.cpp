/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void count(string& str, int & zeroCount, int & oneCount)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0') zeroCount++;
            else oneCount++;
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty() || (!m && !n)) return 0;
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1, 
                                    vector<vector<int>>(m + 1, 
                                    vector<int>(n + 1, 0)));

        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    int temp_m = 0, temp_n = 0;
                    count(strs[i - 1], temp_m, temp_n);
                    if (temp_m <= j && temp_n <= k)
                    {
                        dp[i][j][k] = max(dp[i - 1][j - temp_m][k - temp_n] + 1, 
                                          dp[i - 1][j][k]);
                    }
                    else
                        dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        return dp[size][m][n];
    }

    int findMaxForm_(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (auto& str : strs)
        {
            int zeros = count(str.begin(), str.end(), '0');
            int ones = str.length() - zeros;
            for (int i = m; i >= zeros; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeors][j - ones]);
                }
            }
        }
        return dp[m][n];
    }

};
// @lc code=end

