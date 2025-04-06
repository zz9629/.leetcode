/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    /*
        memo[i] 代表以i结束时(存储 s[0:i])的 possible sentences 
        计算memo[i], 向前遍历 j 从0 到i -1即s 的所有子串。
        如果s[j:i]可以组成一个单词，那么拼接memo[i] = memo[j] + word[i, j]
        eg:
        对于s = “catsanddog”, dict = {"cat","cats","and","sand","dog"};
        memo[3] = {"cat"}, memo[4] = {"cats"}
        memo[7] = {"cat sand", "cats and"}
            // memo[3] + "sand", memo[4] + "and"
        memo[10] = memo[7] + "dog" = {"cat sand dog", "cats and dog"}
    */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo; // 这里用map进行空间优化
        // vector<vector<string>> memo(s.length() + 1, vector<string>());
        int len = s.length();
        for (int i = 1; i <= len; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                // 先判断单词是否存在 会快一点
                // string_view str(s.data() + j, i - j);
                string str = s.substr(j, i - j);
                if (!dict.count(str))
                {
                    continue;
                }

                if (j == 0)
                {
                    memo[i].emplace_back(str);
                }
                else if (!memo[j].empty()) 
                {
                    // 添加新的组合
                    for (auto& vec: memo[j])
                    {
                        // 用emplace_back代替push_back，避免字符串拼接造成的额外拷贝
                        memo[i].emplace_back(vec + " " + str);
                    }
                }
            }
        }
       
        return memo[len];
    }
};  
// @lc code=end

int main()
{
    Solution s;
    vector<string> dict = {"cat","cats","and","sand","dog"};
    auto res =  s.wordBreak("catsanddog", dict);
    return 0;
}