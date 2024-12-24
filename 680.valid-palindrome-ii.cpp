/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include "string"
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int head, int tail)
    {
        if (s.empty()) return false;
        while (head <= tail) 
        {
            if (s[head] != s[tail]) return false;
            head++;
            tail--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        if (s.empty()) return false;
        int head = 0, tail = s.length() - 1;
        while (head <= tail) 
        {
            if (s[head] == s[tail])
            {
                head++;
                tail--;
            } 
            else {
                return isPalindrome(s, head + 1, tail) || 
                    isPalindrome(s, head, tail - 1);
            }
        }
        return true;
    }
};
// @lc code=end

