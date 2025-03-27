/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    bool compareMaps(std::unordered_map<char, int> & mapA, 
                     std::unordered_map<char, int> & mapB)
    {
        for (auto item: mapA)
        {
            if (mapB[item.first] != item.second) 
            {
                return false;
            }
        }
        return true;
    }

    // 使用map
    bool isAnagram_(string s, string t) {
        std::unordered_map<char, int> mapA, mapB;
        for (auto & c: s)
        {
            mapA[c]++;
        }
        for (auto & c: t)
        {
            mapB[c]++;
        }
        if (mapA.size() > mapB.size()) return compareMaps(mapA, mapB);
        else return compareMaps(mapB, mapA);
    }

    bool _isAnagram_(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> counts(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }

        for (auto num: counts)
        {
            if (num) return false;
        }
        return true;
    }


    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(128, 0);
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (auto num: count)
        {
            if (num) return false;
        }
        return true;
    }

};
// @lc code=end

int main()
{
    for (auto i = 1; i <= 128; i++)
    {
        cout << char(i) << " ";
    }

    for (auto i = '1'; i <= '9'; i++)
    {
        cout << int(i) << " ";
    }

    return 0;
}