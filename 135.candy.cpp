/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include "vector"
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> candys(len, 1);
        for (int i = 1; i < len; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candys[i] = candys[i - 1] + 1;
            }
        }
        for (int i = len - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
        }
        return accumulate(candys.begin(), candys.end(), 0);
    }
};
// @lc code=end

