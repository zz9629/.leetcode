/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <vector>
using namespace std;
// @lc code=start
#include <unordered_map>
class Solution {
public:
    // std::unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
    //                                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    //                                         {'8', "tuv"}, {'9', "wxyz"}};
    // 可以用vector更简洁
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string& digits, int i, string & cur, vector<string>& result)
    {
        if (i == digits.length())
        {
            result.push_back(cur);
            return;
        }
        
        int index = digits[i] - '0';
        if (index < 2 || index > 9) return;
        // if (!map.count(digits[i]))
        // {
        //     return;
        // }
        for (auto& item : mapping[index])
        // for (auto& item : map[digits[i]])
        {
            cur.push_back(item);
            helper(digits, i + 1, cur, result);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return {};
        string cur = "";
        helper(digits, 0, cur, result);
        return result;
    }
};
// @lc code=end

