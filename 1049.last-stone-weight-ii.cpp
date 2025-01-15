/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

#include "vector"
#include "math.h"
using namespace std;

// @lc code=start
#include <numeric>
class Solution {
public:
    // @pokehunter
    /*
    (dp[i][j] means the max value of putting the first i number into a backpack with capacity of j):
    the original is supposed to be cut in two subsets, 
    the the closer of sum of them, the minimum diff we can get. 
    the best result is they each equal to sum/2. 
    if that is not possible, then try one subset a bit smaller than sum/2, if still not possible, keep trying this way, until reach to a value close to sum/2. 
    In that case, we get a minimum result
    */
    int lastStoneWeightII_(vector<int>& stones) {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        
        vector<int> dp(sum / 2 + 1, 0);

        for (auto& num : stones)
        {
            for (int j = sum / 2; j >= num; j--)
            {
                dp[j] = max(dp[j], dp[j - num] + num);
            }
        }
        return sum - 2 * dp[sum / 2];
    }

    int lastStoneWeightII(vector<int>& stones) {

    }
};
// @lc code=end

