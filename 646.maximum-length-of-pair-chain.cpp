/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        std::sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int res = 1;
        int end = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > end)
            {
                res++;
                end = pairs[i][1];
            }
            else continue;
        }
        return res;
    }
};
// @lc code=end

