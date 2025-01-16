/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to buy and Sell Stock
 */

// @lc code=start
#include <climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = INT_MAX;
        for (auto& price: prices)
        {
            buy = min(buy, price);
            profit = max(profit, price - buy);
        }

        return profit;
    }
};
// @lc code=end

