/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */
#include <climits>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX - 1);
        dp[0] = 0;
        unordered_map<int, int> tickets;
        tickets[1] = costs[0];
        tickets[7] = costs[1];
        tickets[30] = costs[2];
        for (int i = 1; i <= days[days.size() - 1] ; i++)
        {
            if (find(days.begin(), days.end(), i) == days.end())
            {
                dp[i] = dp[i - 1];
                continue;
            }
            for (const auto& ticket : tickets) {
                dp[i] = min(dp[i], dp[max(0, i - ticket.first)] + ticket.second);
            }
        }
        return dp[days[days.size() - 1]];
        // vector<int> weights{1, 7, 30};
        // for (int j = 1; j <= D; j++)
        // {
        //     for (int i = 0; weights[i] <= j; i++)
        //     {
        //         if (days[j - 1] <= days[j - weights[i]])
        //         {
        //             dp[j] = min(dp[j], dp[j - weights[i]] + costs[i]);
        //         }
        //     }
        // }
        // return dp[D];
    }
};
// @lc code=end

