/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include "vector"
using namespace std;

// @lc code=start
#include <algorithm>
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size())
        {
            if (g[child] <= s[cookie])
            {
                child += 1;
            }
            cookie += 1;
        }
        return child;
    }
};
// @lc code=end

