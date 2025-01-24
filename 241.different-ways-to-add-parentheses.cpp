/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
#include <cstddef>
#include <string>
#include <vector>
#include "iostream"

using namespace std;

// @lc code=start

class Solution {
public:
    int toInt(string & str, int left, int right)
    {
        int res = 0;
        for (int i = left; i <= right; i++)
        {
            res = res * 10 + str[i] - '0';
        }
        return res;
    }

    int compute(int a, int b, char c)
    {
        if (c == '-') return a - b;
        else if (c == '+') return a + b;
        else if (c == '*') return a * b;
        else return a / b;
    }

    vector<int> getPos(string& expression, int left, int right)
    {
        vector<int> pos;

        for (int i = left; i <= right; i++)
        {
            if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*')
            {
                pos.push_back(i);
            }
        }

        return pos;
    }

    vector<int> diffWays(string& expression, int left, int right, vector<vector<vector<int>>>& dp)
    {
        if (left > right) return vector<int>();
        if (!dp[left][right].empty()) return dp[left][right];

        // 操作符的下标
        vector<int> posArr = getPos(expression, left, right);
        if (posArr.empty()){
            dp[left][right].push_back(toInt(expression, left, right));
            return dp[left][right];
        }
        // 利用分治思想，把加括号转化为，对每个运算符号，先执行两侧的表达式，再处理此符号。
        for (auto & pos : posArr)
        {
            std::vector<int> leftArr = diffWays(expression, left, pos - 1, dp);// expression.substr(0, pos)
            std::vector<int> rightArr = diffWays(expression, pos + 1, right, dp); // expression.substr(pos + 1, expression.length() - pos - 1)
            for (auto & l : leftArr)
            {
                for (auto & r : rightArr)
                {
                    dp[left][right].push_back(compute(l, r, expression[pos]));
                }
            }
        }
        
        return dp[left][right];
    }

    vector<int> diffWaysToCompute_(string expression) {
        int n = expression.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        return diffWays(expression, 0, n - 1, dp);
    }

    vector<int> diffWaysToCompute(string expression) {
    }

};
// @lc code=end

int main()
{
    Solution s;
    string str = "2-1-1";
    auto pos = s.getPos(str, 0, str.length() - 1);
    auto res = s.diffWaysToCompute(str);

    return 0;
}