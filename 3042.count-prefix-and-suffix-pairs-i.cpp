/*
 * @lc app=leetcode id=3042 lang=cpp
 *
 * [3042] Count Prefix and Suffix Pairs I
 // 3045. Count Prefix and Suffix Pairs II
 */
#include "iostream"

using namespace std;
// @lc code=start
class Solution {
    public:
        bool isPrefixAndSuffix(const string &word, const string &suffix) {
            if (suffix.size() > word.size()) return false;
            return word.substr(word.size() - suffix.size()) == suffix &&
                    word.substr(0, suffix.size()) == suffix;
        }
        int countPrefixSuffixPairs(vector<string>& words) {
            int count = 0;
            int n = words.size();
    
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (words[j].length() >= words[i].length() && 
                        isPrefixAndSuffix(words[j], words[i])){
                        count++;
                    }
                }
            }
    
            return count;
        }
    };
// @lc code=end


int main()
{
    vector<string> words = {"abab","ab"};
    Solution s;
    cout << s.countPrefixSuffixPairs(words) << endl;

    return 0;
}