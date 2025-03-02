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
    void calLsp(const string& needle, vector<int>& next)
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
         

    int strStr_(string haystack, string needle) {
        if (needle.empty()) return -1;
        int k = -1;
        int n = haystack.length(), p = needle.length();
        vector<int> next(needle.length(), -1);  // Longest Prefix Suffix 
        calLsp(needle, next);

        for (int i = 0; i < haystack.length(); i++)
        {
            while (k > -1 && needle[k + 1] != haystack[i])
            {
                k = next[k]; // 部分匹配，往前回溯
            }

            if (needle[k + 1] == haystack[i])
            {
                k++;
            }

            if (k == p - 1)
            {
                return i - p + 1;
            }
        }

        return -1;
    }

    void getLsp(string & needle, vector<int> & lsp)
    {
        int p = -1;
        for (int i = 1; i < needle.length(); i++)
        {
            while (p > - 1 && needle[p + 1] != needle[i])
            {
                p = lsp[p];
            }
            if (needle[p + 1] == needle[i])
            {
                p++;
            }
            lsp[i] = p;
        }
    }
    
    // haystack = "ababcabcabababd", needle = "ababd"
    int strStr__(string haystack, string needle) {
        if (needle.empty()) return -1;
        int j = -1;        
        vector<int> lsp(needle.length(), -1);
        getLsp(needle, lsp);
        for (int i = 0; i < haystack.length(); i++)
        {
            while (j > - 1 && needle[j + 1] != haystack[i])
            {
                j = lsp[j];
            }
            if (needle[j + 1] == haystack[i])
            {
                j++;
            }
            if (j == needle.length() - 1)
            {
                return i - j;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.length(), -1);
        calLsp(needle, lps);
        int j = -1;
        for (int i = 0; i < haystack.length(); i++)
        {
            while (j > -1 && needle[j + 1] != haystack[i])
            {
                j = lps[j];
            }
            if (needle[j + 1] == haystack[i])
            {
                j++;
            }
            if (j == needle.length() - 1)
            {
                return i - j;
            }
        }
        return -1;
    }
    

};
// @lc code=end

int main()
{
    Solution s;
    s.strStr_("ababcabcabababd", "ababd");
    s.strStr_("AAA", "AAACAAAA");
    // s.strStr("sadbutsad", "sasad");

    return 0;
}

