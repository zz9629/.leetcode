/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */
#include "vector"
using namespace std;
#include "string"
#include "iostream"
// @lc code=start
#include <unordered_map>
class Solution {
public:
    // 记录相同字母的pos, 如果需要更改的话，全部换掉。最后比较两个字符串是否相等
    // Case Failed: "badc". "baba"
    bool isIsomorphic__(string s, string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char, vector<int>> pos;
        for (int i = 0; i < s.length(); i++)
        {
            pos[s[i]].push_back(i);
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[i])
            {
                continue;
            }
            auto target = t[i];
            auto source = s[i];
            auto list = pos[source];
            for (auto index: list)
            {
                s[index] = target;
            }
        }

        return s == t;
    }

    bool isIsomorph_ic(string s, string t) {
        vector<int> s_first_index(256, 0), t_first_index(256, 0);// ascii码
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s_first_index[s[i]] != t_first_index[t[i]]) return false;
            int index = s[i], index2 = t[i];
            cout << index << " " << index2 << endl;
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;  // 区别默认值0与位置0
        }
        return true;
    }

    bool isIsomorphic___(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> mapST, mapTS;
        for (int i = 0; i < s.length(); i++)
        {
            if ((mapST.find(s[i]) != mapST.end() && mapST[s[i]] != t[i]) ||
                (mapTS.find(t[i]) != mapTS.end() && mapTS[t[i]] != s[i]))
                {
                    return false;
                }
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
    }

};
// @lc code=end

int main()
{

    Solution s;
    s.isIsomorphic("foo", "bar");
    return 0;
}