/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
/*
计算机问题
[224] Basic Calculator I,  "+ - ( )"
[227] Basic Calculator II, "+ - * /"
[772] Basic Calculator III (locked), "+ - * / ( )"

Here are some examples:

"1 + 1" should output: 2

" 6-4 / 2 " should output: 4

"2*(5+5*2)/3+(6/2+8)" should output: 21

"(2+6* 3+5- (3*14/7+2)*5)+3" should output: -12

思路：https://leetcode.com/problems/basic-calculator/solutions/1456850/python-basic-calculator-i-ii-iii-easy-solution-detailed-explanation/

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

 */

#include "stack"
#include "iostream"
#include <numeric>
#include <valarray>
 using namespace std;
// @lc code=start
class Solution {
public:
    bool isDigit(char c)
    {
        return (c >= '0' && c <= '9');
    }

    // https://www.youtube.com/watch?v=BjDczS5uQ-g 
    int calculate_stack(string s) {
        // signed integer overflow
        long long int result = 0;
        int sign = 1;
        stack<int> plate;
        for (int i = 0; i < s.length(); i++)
        {
            if (isDigit(s[i])) 
            {
                // signed integer overflow
                long long int cur = s[i] - '0';
                while (i + 1 < s.length() && isDigit(s[i + 1]))
                {
                    cur = cur * 10 + s[i + 1] - '0';
                    i++;
                }
                result += sign * cur;
            }
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            // 把当前结果、符号入栈。在里面算一个全新的值。
            // 入栈，可以理解为调用函数，需要将当前结果压入栈。
            else if (s[i] == '(')
            {
                plate.push(result);
                plate.push(sign);
                result = 0; //初始化result和sign
                sign = 1;
            }
            // 算完括号里面的数据之后再乘括号前面的符号，加起来。
            else if (s[i] == ')')
            {
                int sign_ = plate.top();
                plate.pop();
                int value = plate.top();
                plate.pop();
                result = sign_ * result + value;
            }
        }

        return result;
    }

    // -------------------------------------------------------------------------
    // [772] Basic Calculator III (locked)
    void update(vector<int>& values, int num, char sign)
    {
        if (sign == '+') values.push_back(num);
        else if (sign == '-') values.push_back(-num);
        else if (sign == '*') values.back() *= num;
        else if (sign == '/') values.back() /= num;
    }

    int calculate_helper(string& s, int start, int& end) {
        vector<int> values;
        long long num = 0;
        char sign = '+';
        string op = "+-*/";
        for (int i = start; i < s.length(); i++)
        {
            if (s[i] == ' ') continue;
            if (isDigit(s[i])) num = num * 10 + s[i] - '0';
            else if (find(op.begin(), op.end(), s[i]) != op.end())
            {
                update(values, num, sign);
                sign = s[i];
                num = 0;
            }
            else if (s[i] == '(') 
            {
                int end = i;
                // 注意i + 1
                // 返回值给num
                num = calculate_helper(s, i + 1, end); 
                i = end;
            }
            else if (s[i] == ')')
            {
                end = i;
                update(values, num, sign); // 返回前更新一下
                return accumulate(values.begin(), values.end(), 0);
            }
        }
        update(values, num, sign); // 返回前更新一下
        return accumulate(values.begin(), values.end(), 0);
    }

    int calculate_III(string& s) {
        int end = 0;
        return calculate_helper(s, 0, end);
    }
    // -------------------------------------------------------------------------


    int helper(string & s, int start, int & end)
    {
        vector<int> values;
        long long num = 0;
        char sign = '+';
        string ops = "+-*/";
        for (int i = start; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == ' ') continue;
            else if (ch >= '0' && ch <= '9') num = num * 10 + ch - '0';
            else if (find(ops.begin(), ops.end(), ch) != ops.end())
            {
                update(values, num, sign);
                sign = ch;
                num = 0;
            }
            else if (ch == '(')
            {
                int j = i;
                num = helper(s, i + 1, j);
                i = j;
            }
            else if (ch == ')')
            {
                end = i;
                update(values, num, sign);
                return accumulate(values.begin(), values.end(), 0);
            }
        }

        update(values, num, sign);
        return accumulate(values.begin(), values.end(), 0);
    }


    int calculate(string& s) {
        int end;
        return helper(s, 0, end);
    }

};
// @lc code=end

int main()
{
    Solution sol;

    string s = "(1+(4+5+2)-3)+(6+8)";
    string t = "2147483647";
    string tt = "2 0 + 2";
    cout << sol.calculate_stack(tt) << endl;

    string com = "2*(5+5*2)/3+(6/2+8)";
    string comp = "(2+6* 3+5- (3*14/7+2)*5)+3";
    cout << sol.calculate_III(com) << endl; // 21
    cout << sol.calculate_III(comp) << endl; // -12

    return 0;
}

