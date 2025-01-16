/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int pre_sell = 0;

        for (auto& price: prices)
        {
            buy = max(buy, pre_sell - price);
            pre_sell = sell;
            sell = max(sell, buy + price);
        }

        return sell;
    }
};
// @lc code=end

