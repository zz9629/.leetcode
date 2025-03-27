/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */
#include "vector"
using namespace std;

// @lc code=start
class Solution {
public:
    // Longest Prefix Suffix 
    void calLps_(const string& needle, vector<int>& next)
    {   
        int p = -1;
        // 计算next[j]的值
        for (int j = 1, p = -1; j < needle.length(); ++j)
        {
            while (p > -1 && needle[p + 1] != needle[j])
            {
                p = next[p]; // 如果下一位不相同，往前回溯
            }
            if (needle[p + 1] == needle[j])
            {
                ++p; // 更新相同的最大前缀和最大后缀长
            }
            next[j] = p;
        }
    }
         
    // haystack = "ababcabcabababd", needle = "ababd"
    int strStr_(string haystack, string needle) {
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


    void calLps(string& needle, vector<int>& lps)
    {
        int p = -1;
        for (int i = 1; i < needle.length(); i++)
        {
            while (p > -1 && needle[p + 1] != needle[i]) {
                p = lps[p];
            }
            if (needle[p + 1] == needle[i])
            {
                p++;
            }
            lps[i] = p;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.length() > haystack.length()) return -1;
        vector<int> lps(needle.length(), -1);
        calLps(needle, lps);
        int p = -1;
        for (int i = 0; i < haystack.length(); i++)
        {
            while (p > -1 && needle[p + 1] != haystack[i])
            {
                p = lps[p];
            }
            if (needle[p + 1] == haystack[i])
            {
                p++;
            }
            if (p == needle.length() - 1)
            {
                return i - p;
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.strStr("ababcabcabababd", "ababd");
    s.strStr("AAA", "AAACAAAA");
    s.strStr("sadbutsad", "sad");

    return 0;
}

