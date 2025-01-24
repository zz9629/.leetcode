/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include "stack"
#include "string"
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> data;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                data.push(s[i]);
                continue;
            }
            if (data.empty()) return false;

            char top = data.top();

            if ((s[i] == ')' && top == '(') ||
                (s[i] == '}' && top == '{') ||
                (s[i] == ']' && top == '[') 
            )
            {
                data.pop();
            }
            else return false;

        }
        return data.empty();
    }
};
// @lc code=end

int main()
{
    Solution s;
    string str = "()[]{}";
    s.isValid(str);
    return 0;
}