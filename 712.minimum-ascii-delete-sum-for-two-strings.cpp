/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */
#include "vector"
#include "string"
#include <algorithm>
#include <climits>
#include <numeric>
#include "iostream"
// @lc code=start

using namespace std;

enum Dir {
    null = 0,
    diagnal,
    right,
    down
};


struct node{
    Dir direction;
    int val;
};

class Solution {
public:
    // wrong solution, not the mininal:
    // get 417 from "delete" and "leet", but the correct answer should be 403
    int minimumDeleteSum_(string s1, string s2) {
        int m = s1.length(), n = s2. length();
        
        vector<vector<node>> dp(m + 1, vector<node>(n + 1, node{null, 0}));
        // vector<vector<int>> dp(m + 1, vector<node>(n + 1, node{false, 0}));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1]) 
                {
                    dp[i][j] = node{Dir::diagnal, dp[i - 1][j - 1].val + 1};
                }
                else if (dp[i - 1][j].val >= dp[i][j - 1].val)
                {
                    dp[i][j] = node{Dir::down, dp[i - 1][j].val};
                }
                else {
                    dp[i][j] = node{Dir::right, dp[i][j - 1].val};
                }
            }
        }

        string comm = "";

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            auto node = dp[i][j];
            if (node.direction == Dir::diagnal)
            {
                comm += s1[i - 1];
                i--;
                j--;
            }
            else if (node.direction == Dir::right) j--;
            else i--;
        }

        int sum = accumulate(comm.begin(), comm.end(), 0);
        int a = accumulate(s1.begin(), s1.end(), 0);
        int b = accumulate(s2.begin(), s2.end(), 0);

        // int res = 0;
        // for (auto c: s1)
        // {
        //     if (std::find(comm.begin(), comm.end(), c) == )
        // }
        return a + b - sum * 2;
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2. length();
 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 相同字符，不需要删除，所有不加入delete sum
                }
                else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1],  // 删除s1[i - 1], s2中的可能有用
                                dp[i][j - 1] + s2[j - 1]);    // 删除s2[j - 1], s1中的可能有用
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.minimumDeleteSum("delete",  "leet");
    string s1 = "delete", s2 = "leet";

    cout << accumulate(s1.begin(), s1.end(), 0);
    
    return 0;
}