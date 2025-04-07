/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <string>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    void updateStr(string & result, string str, int num)
    {
        if (num == 0)
        {
            result += str;
        }
        else {
            while (num--)
            {
                result += str;
            }
        }
    }

    bool isDigit(char ch)
    {
        return '0' <= ch && ch <= '9';
    }

    bool isLetter(char ch)
    {
        return 'a' <= ch && ch <= 'z';
    }

    string helper_(string s, int start, int& end)
    {
        string result = "";

        string str = "";
        int num = 0;
        for (int i = start; i < s.length(); i++)
        {
            if (isDigit(s[i]))
            {
                updateStr(result, str, num);

                num = s[i] - '0';
                while (i + 1 < s.length() && isDigit(s[i + 1]))
                {
                    i++;
                    num = num * 10 + s[i] - '0';
                }
            }
            else if (isLetter(s[i])) 
            {
                str = s[i];
                while (i + 1 < s.length() && isLetter(s[i + 1]))
                {
                    i++;
                    str += s[i];
                }
            }
            else if (s[i] == '[')
            {
                int j = i;
                str = helper(s, i + 1, j);
                i = j;

                updateStr(result, str, num);
                num = 0;
                str = "";
            }
            else if (s[i] == ']')
            {
                end = i;
                updateStr(result, str, num);
                return result;
            }
        }
        
        updateStr(result, str, num);
        return result;
    }

    string helper(string s, int start, int& end)
    {
        string result = "";
        int num = 0;
        for (int i = start; i < s.length(); i++)
        {

            if (isDigit(s[i])) num = num * 10 + s[i] - '0';
            else if (isLetter(s[i])) result += s[i];
            else if (s[i] == '[')
            {
                int j = i;
                auto str = helper(s, i + 1, j);
                i = j;

                updateStr(result, str, num);
                num = 0;
            }
            else if (s[i] == ']')
            {
                end = i;
                // updateStr(result, str, num);
                return result;
            }
        }
        
        // updateStr(result, str, num);
        return result;
    }


    string decodeString(string s) {
        int end = 0;
        return helper(s, 0, end);
    }
};
// @lc code=end


int main()
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl; // "aaabcbc"
    cout << s.decodeString("3[a2[c]]"); // accaccacc"
    return 0;
}