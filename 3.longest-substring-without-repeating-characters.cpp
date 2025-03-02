/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include "string"
#include "unordered_map"
#include <unordered_set>
#include "iostream"

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstrin__(string s) {
        unordered_map<char, int> chars;
        int counter = 0;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.size())
        {
            chars[s[right]]++;
            if (chars[s[right]] > 1) 
            {
                counter++;
            }
            right++;

            while (counter > 0)
            {
                chars[s[left]]--;
                if (chars[s[left]]== 1) counter--;
                left++;
            }

            if (right - left > max_len)
            {
                max_len = right - left;
            }
        }
        return max_len;
    }

    int lengthOfLongestSubstring_(string s) {
        int left = 0, right = 0;
        int res_left = 0, res_len = 0;
        unordered_map<char, int> chars;
        int counter = 0;
        while (right < s.size())
        {
            auto c = s[right];
            if (chars[c] > 0) counter++; // repeat time
            chars[c]++;
            right++;
            while (counter > 0) // as long as there is a repeat
            {
                auto c_left = s[left];
                if (chars[c_left] == 2) counter--;
                chars[c_left]--;
                left++;
            }
            if (right - left > res_len)
            {
                res_left = left;
                res_len = right - left;
            }
        }
        return res_len;
    }

    int lengthOfLongestSubstring__(string s) {
        int counter = 0;
        int left = 0, right = 0;
        unordered_map<char, int> chars;
        int max_len = 0;
        while (right < s.size())
        {
            chars[s[right]]++;
            if (chars[s[right]] > 1) counter++;
            right++;

            while (counter > 0) 
            {
                chars[s[left]]--;
                if (chars[s[left]] == 1) counter--;
                left++;
            }
            max_len = max(max_len, right - left);
        }

        return max_len;
    }

    int lengthOfLongestSubstring___(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> chars;
        int len = s.length();
        int repeat = 0;
        int max_len = 0;
        while (right < len) 
        {
            chars[s[right]]++;
            if (chars[s[right]] > 1) repeat++;
            right++;

            while (repeat > 0)
            {
                chars[s[left]]--;
                if (chars[s[left]] == 1) repeat--;
                left++;
            }
            max_len = max(right - left, max_len);
        }
        return max_len;
    }

    int lengthOfLongestSubstring(string s) {
         
    }

};
// @lc code=end

int main()
{

    Solution s;
    s.lengthOfLongestSubstring("abcbb");
    return 0;
}