/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */
#include "string"
#include <numeric>
#include "iostream"
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int head, int tail)
    {
        if (s.empty()) return false;
        while (head <= tail) 
        {
            if (s[head] != s[tail]) return false;
            head++;
            tail--;
        }
        return true;
    }

    /* error code, fail to judge a palindromic string
    bool isPalindromic(string& s, int i, int j) 
    {
        if (i > j || i >= s.length() || j >= s.length()) return false;
        if (i == j) return true;
        if (s[i] != s[j]) return false;
        return isPalindromic(s, i + 1, j - 1);
    }
    */
    int force(string s)
    {
        int n = s.length();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (isPalindrome(s, j, i)) dp[i]++;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

    int countSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int ans = 0;
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            /*
            // ans++;
            // memo[i][i] = true;
            for (int j = i; j >= 0; j--)
            {
                if (s[i] == s[j])
                {
                    if (i - j <= 2) 
                    {
                        memo[j][i] = true;
                    } 
                    else {
                        memo[j][i] = memo[j + 1][i - 1];
                    }
                    if (memo[j][i])  ans++;
                }
                
            }
            */
            // improved: 
            for (int j = i; j >= 0; j--)
            {
                if (s[i] == s[j] && (i - j <= 2 || memo[j + 1][i - 1]))
                {
                    memo[j][i] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.countSubstrings("abc");

    return 0;
}

