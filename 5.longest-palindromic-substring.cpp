/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include "iostream"
#include "string"
#include "vector"

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome_bool(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n, vector<bool>(n, false));

        int len = 0;
        string res;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if (i - j + 1 > len)
                    {   
                        len = i - j + 1;
                        res = s.substr(j, len);
                    }
                }
            }
        }
        return res;
    }

    string longestPalindrome(string s) {

    }

};
// @lc code=end

int main()
{
    string str("aaaa");
    Solution s;
    cout << s.longestPalindrome_bool(str);

    return 0;
}