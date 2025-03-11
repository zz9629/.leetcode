/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

/* 
1. Use two pointers: start and end to represent a window.
2. Move end to find a valid window.
3. When a valid window is found, move start to find a smaller window.
*/

#include "string"
#include "unordered_map"
#include <unordered_set>
#include "iostream"

using namespace std;

// @lc code=start
class Solution {
public:
    // 159. Longest Substring with At Most Two Distinct Characters
    /*
        For example, in the string "aabacbebebe," 
        the longest substring with at most two distinct characters is "cbebebe," 
        which has a length of 7.
    */

    string longestKSubstr(string s, int k)
    {
        unordered_map<char, int> chars;
        int left = 0, right = 0;
        int max_len = 0;
        string res;
        int count = 0;

        while (right < s.length())
        {
            if (chars[s[right]] == 0) count++;
            chars[s[right]]++;
            right++;

            while (count > k)
            {
                chars[s[left]]--;
                if ( chars[s[left]] == 0) count--;
                left++;
            }

            if (right - left > max_len)
            {
                max_len = right - left;
                res = s.substr(left, max_len);
            }

        }
        return res;
    }


    string longestKSubstr__(string s, int k)
    {
        int left = 0, right = 0;
        int res_left = 0, res_len = 0;
        int counter = 0;
        unordered_map<char, int> chars;
        while (right < s.size())
        {
            if (chars[s[right]] == 0) counter++;
            chars[s[right]]++;
            right++;

            while (counter > k)
            {
                chars[s[left]]--;
                if (chars[s[left]] == 0) counter--;
                left++;
            }

            if (right - left > res_len)
            {
                res_len = right - left;
                res_left = left;
            }
        }

        return s.substr(res_left, res_len);
    }


    string longest2Substr(string s)
    {
        int left = 0, right = 0;
        int min_left = 0, max_len = 0;
        unordered_map<char, int> chars;
        int counter = 0;
        while (right < s.size())
        {
            auto c = s[right];
            if (chars[c] == 0) counter++;
            chars[c]++;
            right++;
            // 这个while在里面
            while (counter > 2)
            {
                auto c = s[left];
                if (chars[c] == 1) counter--;
                chars[c]--;
                left++; // right left都是往右，都是++
            }
            if (right - left > max_len)
            {
                max_len = right - left;
                min_left = left;
            }
        }
        return s.substr(min_left, max_len);
    }

    string longest2Substr_(string s)
    {
        int left = 0, right = 0;
        int min_left = 0, max_size = 0;
        unordered_map<char, int> chars;
        int counter = 0;
        while (right < s.size())
        {
            auto c = s[right];
            if (chars[c] == 0) {
                counter++;
            } 
            right++;
            chars[c]++;
            while (counter > 2)
            {
                auto left_char = s[left];
                if (chars[left_char] == 1) counter--;
                chars[left_char]--;
                left++;
            }
            if (right - left > max_size)
            {
                max_size = right - left;
                min_left = left;
            }
        }
        return s.substr(min_left, max_size);
    }

    string minWindow_(string s, string t) {
        // 统计需要的个数，取值的时候不要把left和right弄混
        unordered_map<char, int> chars;
        for (auto c : t){
            chars[c]++;
        }
        // right to find valid window, left to find smaller window
        int left = 0, right = 0;
        // 注意min_size取的是s的长度，而不是t的长度
        int min_left = 0, min_size = s.size() + 1; // record
        // counter represents the number of chars of t to be found in s.
        int counter = t.size();  // 剪枝
        int size = s.size();

       	// Move end to find a valid window.
        // 可以换成while (right < s.length()) ，在里面right++, 长度计算为rihgt-left
        for (right = 0; right < size; right++)
        {
            // If char in s exists in t, decrease counter
            auto c = s[right];
            if (chars[c] > 0)
            {
                counter--; // 找到一个需要的char
            }
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            chars[c]--;
            // When we found a valid window, move start to find smaller window.
            while (counter == 0)
            {
                // update
                if (right - left + 1 < min_size)
                {
                    min_size = right - left + 1;
                    min_left = left;
                }
                auto left_c = s[left];
                chars[left_c]++;
                if (chars[left_c] > 0)
                {
                    counter++;
                }
                left++;
            }
        }
        return min_size > s.size() ? "" : s.substr(min_left, min_size);
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> chars;
        for (auto & c : t)
        {
            chars[c]++;
        }
        int counter = t.size();

        int left = 0;
        int right = 0;
        int min_len = s.size() + 1;
        int pos = 0;
        while (right < s.length())
        {
            if (chars[s[right]] > 0) counter--;
            chars[s[right]]--;
            right++;

            while (counter == 0)
            {
                if (right - left < min_len)
                {
                    min_len = right - left;
                    pos = left;
                }
                chars[s[left]]++;
                if (chars[s[left]] > 0) counter++;
                left++;
            }
        }

        return min_len > s.size() ? "" : s.substr(pos, min_len);
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.minWindow("ABDCOBECODEBANC", "ABC") << endl;
    
    // auto res = s.longest2Substr("eceba");
    // cout << res << endl;
    // cout << s.longest2Substr("ccaabbb") << endl;

    // cout << s.longestKSubstr("eceba", 2) << endl;
    // cout << s.longestKSubstr("aa", 1) << endl;

    return 0;
}