/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman_(int num) {
        vector<pair<int, string>> map{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
                                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, 
                                {1, "I"}};
        string res;
        for (auto & [value, symbol] : map)
        {
            if (num == 0) break;
            while (num >= value) 
            {
                res += symbol;
                num -= value;
            }
        }
        return res;
    }



    string intToRoman(int num) {
        return "";
    }
};
// @lc code=end

