/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

 #include "string"
 #include "vector"
 using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings_(string s) {
        int n = s.size();
        s = " " + s;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int a = s[i] - '0';
            int b = (s[i - 1] - '0') * 10 + a;
            if (1 <= a && a <= 9) dp[i] = dp[i - 1];
            if (10 <= b && b <= 26) dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }


    int numDecodings(string s) {
        
    }

};
// @lc code=end

int main()
{
    Solution s;
    s.numDecodings("226");

    return 0;
}