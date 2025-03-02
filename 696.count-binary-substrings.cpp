/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */
#include "vector"
#include "string"
using namespace std;

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        /*

        if (s.empty()) return 0;
        vector<int> count;
        char cur = s[0];
        int temp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == cur) temp++;
            else 
            {
                count.push_back(temp);
                cur = s[i];
                temp = 1;
            }
        }
        count.push_back(temp); // ！！最后的结果也要放进去

        int result = 0;
        for (int i = 0; i < count.size() - 1; i++)
        {
            result += min(count[i], count[i + 1]);
        }

        return result;

        */
        
        // 优化
        int cur = 1, pre = 0, result = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1]) cur++;
            else
            {
                result += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return result += min(cur, pre);
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.countBinarySubstrings("00110011");
    return 0;
}