/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

/*
    // Longest Prefix Suffix 
    void calLps(const string& needle, vector<int>& lps)
    {   
        int p = -1;
        // 计算next[j]的值
        for (int j = 1, p = -1; j < needle.length(); ++j)
        {
            while (p > -1 && needle[p + 1] != needle[j])
            {
                p = lps[p]; // 如果下一位不相同，往前回溯
            }
            if (needle[p + 1] == needle[j])
            {
                ++p; // 更新相同的最大前缀和最大后缀长
            }
            lps[j] = p;
        }
    }
         
    // haystack = "ababcabcabababd", needle = "ababd"
    int findFirstIndex(string& haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        vector<int> lps(needle.length(), -1);
        calLps(needle, lps); // 用lps，否则容易将next和needle写混

        int pos = -1;
        for (int i = 0; i < haystack.length(); i++)
        {
            while (pos > -1 && needle[pos + 1] != haystack[i])
            {
                pos = lps[pos];  // 部分匹配，往前回溯
            }
            if (needle[pos + 1] == haystack[i])
            {
                pos++;
            }
            if (pos == needle.length() - 1)
            {
                return i - pos;
            }
        }
        return -1;
    }

    bool wordBreak_(string s, vector<string>& wordDict) {
        std::unordered_set<string> dict;
        std::queue<string> unverified;
        unverified.push(s);
        for (auto & needle: wordDict)
        {
            if (dict.count(needle)) 
            {
                continue;
            }
            
            int pos = -1;
            int size = unverified.size();
            while (size--)
            {
                auto haystack = unverified.front();
                unverified.pop();

                pos = findFirstIndex(haystack, needle);
                if (pos == -1)
                {
                    unverified.push(haystack);
                    continue;
                }
                else 
                {
                    dict.insert(needle);
                    auto left = haystack.substr(0, pos);
                    auto right = haystack.substr(pos + needle.length(), haystack.length() - pos - needle.length());
                    unverified.push(left);
                    unverified.push(right);
                    break;
                }
            }
            if (pos == -1) return false;
        }
        return true;
    }
*/
    // 能否用wordDict凑成s

    // 1. force recursive
    bool helper(string s, unordered_set<string>& dict, unordered_map<string, bool> & map)
    {
        int len = s.length();
        if (s.empty()) return true;

        if (map.find(s) != map.end())
        {
            return map[s];
        }

        for (int i = 1; i <= len; i++)
        {
            if (dict.count(s.substr(0, i)) && helper(s.substr(i), dict, map))
            {
                map[s] = true;
                return true;
            }
        }
        map[s] = false;
        return false;
    }

    // 2. map for memorize
    bool wordBreak__(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> map;
        return helper(s, dict, map);
    }

    // 3. dp
    /*
    Time Complexity O(n²) Space Complexity O(n) + set.
    dp[i] = true if the substring s[0..i-1] (first i characters) can be broken into valid dictionary words.
    Example: For s = "leetcode" and dict = ["leet", "code"], dp[4] = true (because "leet" is valid) and dp[8] = true (because "leet" + "code" is valid).
    
    For each position i, check all possible splits j (0 ≤ j < i):
    If dp[j] = true and the substring s[j..i-1] exists in dict, then dp[i] = true.
    
    */
     bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, false);
        dp[0] = true;
        int len = s.length();
        for (int i = 1; i <= len; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j]) 
                {
                    if (dict.count(s.substr(j, i - j)))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[len];
    }
};
// @lc code=end

int main()
{   
    string s = "bb";
    vector<string> words = {"a","b","bbb","bbbb"};
    Solution sol;
    cout << sol.wordBreak(s, words);
    return 0;
}