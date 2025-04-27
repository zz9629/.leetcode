/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <set>

using namespace std;
// @lc code=start
class Solution {
public:

    void dfs(int n, int left, int right, vector<string>& res, string temp)
    {
        if (temp.length() == 2 * n) 
        {
            res.push_back(temp);
            return;
        }
        if (left < n)
        {
            dfs(n, left + 1, right, res, temp + "(");
        }
        if (right < left)
        {
            dfs(n, left, right + 1, res, temp + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        // vector<set<string>> dp(n + 1, set<string>());
        // dp[1].insert("()");

        // for (int i = 2; i <= n; i++)
        // {
        //     for (auto & item: dp[i - 1])
        //     {
        //         dp[i].insert(item + "()");
        //         dp[i].insert("()" + item);
        //         dp[i].insert("(" + item + ")");
        //     }
        // }

        // vector<string> res(dp[n].begin(), dp[n].end());
        // return res;
        vector<string> res;
        string temp;
        dfs(n, 0, 0, res, temp);
        return res;
    }
};
// @lc code=end

