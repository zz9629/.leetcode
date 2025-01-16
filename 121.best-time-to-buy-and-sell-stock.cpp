/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to buy and Sell Stock
 */

/*
    @VictorSong2021: httprices://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/solutions/740596/5xing-dai-ma-gao-ding-suo-you-gu-piao-ma-j6zo/
*/

// @lc code=start
#include <climits>
class Solution {
public:
    int naiveProfit(vector<int>& prices)
    {
        int n = prices.size();
        // 这道题只能交易一次股票， 不能当天买，当天卖。
        // 在每一天结束的时候的状态其实可以分成 2种：
        // 1. 买过股票了（buy）, 有可能是前一天就处于买过股票的状态，或者是第一次买。
        // 2. 卖过股票了 (sell), 有可能是前一天就处于卖过股票的状态，或者是今天一开始处于
        //    买过股票的状态，但是后来又卖掉了当天的股票。
        // 其实还有一种状态就是，当天结束的时候，既没有处于买过股票的状态，也没有处于 sell
        // 股票的状态。这种状态没有任何操作，收益肯定是 0，所以没有必要研究。其实 sell 里
        // 包含了这种状态，由于一开始 sell[0] 设为了 0，
        // buy[i]: 代表在第 i 天处于买过股票的状态，在当天结束的时候能获得的最大收益。
        // sell[i]: 代表在第 i 天处于卖过股票的状态，在当天结束的时候能获得的最大收益。
        vector<int> buy(n + 1, INT_MIN);
        vector<int> sell(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // 注意 prices[i - 1] 就是 第 i 天的价格，不是前一天的价格。
            buy[i] = max(buy[i - 1], - prices[i - 1]);
            // sell[0] = 0 这个默认的初始值，保证了一次交易以后的最大收益最小也得是 0， 不能出现负数，
            sell[i] = max(sell[i - 1], buy[i] + prices[i - 1]);
        }
        // 最后一天结束的时候，肯定会完成 1 次交易，这个时候就处于卖过股票的状态，返回这个状态下的最大收益。
        return sell[n];
    }

    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN;
        for (auto& price: prices)
        {
            // 等号左边的 buy 代表的是遍历到的今天处于买过股票的状态，等号右边的 buy 代表的是今天的前一天处于买过股票的状态。
            buy = max(buy, 0 - price);
            sell = max(sell, buy + price);
        }

        return sell;
    }
};
// @lc code=end

