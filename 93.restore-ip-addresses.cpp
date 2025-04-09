/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

/*
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Input: s = "0000"
Output: ["0.0.0.0"]

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/
// @lc code=start
class Solution {
public:
    void addStr(vector<string> & prev, vector<string> & cur, string str)
    {
        if (prev.empty())
        {
            cur.push_back(str);
        }
        else {
            for (auto &item :prev)
            {
                // 优化，含有"."过多的不考虑
                if (count(item.begin(), item.end(), '.') < 3)
                {
                    cur.emplace_back(item + "." + str);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        int len = s.length();
        if (len < 4 || len > 12) return {};

        s = "  " + s;
        vector<vector<string>> dp(len + 2, vector<string>());
        // dp[2] = { s.substr(2, 1) }; 

        for (int i = 2; i < len + 2; i++)
        {
            int a = s[i] - '0'; // dp[i] = dp[i - 1];
            int b = (s[i - 1] - '0') * 10 + a; // dp[i] += dp[i - 1];
            int c = (s[i - 2] - '0') * 100 + b; // dp[i] += dp[i - 2];

            // if (0 <= a && a <= 9)
            {
                addStr(dp[i - 1], dp[i], s.substr(i, 1));
            }
            if (10 <= b && b <= 99)
            {
                addStr(dp[i - 2], dp[i], s.substr(i - 1, 2));
            }
            if (100 <= c && c <= 255) 
            {
                addStr(dp[i - 3], dp[i], s.substr(i - 2, 3));
            }
        }

        for (auto& item: dp[len + 1])
        {
            // 1. 需要完整字符串，否则会false positive "530474625546" -> ["5.5.4.6"]
            // 2. 需要含有3个".
            if (item.length() > len && count(item.begin(), item.end(), '.') == 3)
            {
                res.push_back(item);
            }
        }

        return res;
    }
};
// @lc code=end

