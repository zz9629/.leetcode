/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

/*
121. Best Time to Buy and Sell Stock
309. Best Time to Buy and Sell Stock with Cooldown
714. Best Time to Buy and Sell Stock with Transaction Fee
123. Best Time to Buy and Sell Stock III
188. Best Time to Buy and Sell Stock IV
*/

#include "vector"
#include <cstddef>
#include <future>
#include "iostream"

using namespace std;
// @lc code=start
class Solution {
public:


    int maxProfitUnlimited(vector<int>& prices)
    {
        /*
            int res = 0;
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        */

        /*
        这两个问题唯一的不同点在于我们是买一次还是买无穷多次，而代码就只有 0-p 和 sell-p 的区别。
        因为如果买无穷多次，就需要上一次卖完的状态。如果只买一次，那么上一个状态一定是0。
        */
        int sell = 0, buy = INT_MIN;
        for (auto& p: prices)
        {
            buy = max(buy, sell - p);
            sell = max(sell, buy + p);
        }
        
        return sell;
    }

    int maxProfit_(int k, vector<int>& prices) {
        int n = prices.size();
        if (k * 2 >= n)
        {
            return maxProfitUnlimited(prices);
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        // 每天都要更新，因为你在扫描的过程中后面可能有更大的单子，
        // 大到可以一个顶俩，所以在遍历完prices之前一定要每天都计算一轮最优解才行
        for (auto& price: prices)
        {
            for (int i = 1; i <= k; i++)
            {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];

        // 二维
        // vector< vector<int>> buy(n + 1, vector<int>(k + 1, INT_MIN));
        // vector< vector<int>> sell(n + 1, vector<int>(k + 1, 0));
        // for (int i = 1; i <= n; i++)
        // {
        //     int p = prices[i - 1];
        //     for (int j = 1; j <= k; j++)
        //     {
        //         buy[i][j] = max(buy[i - 1][j - 1], sell[i - 1][j - 1] - p);
        //         sell[i][j] = max(sell[i - 1][j], buy[i][j] + p);
        //     }
        // }

        // return sell[n][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (2 * k >= n) return maxProfitUnlimited(prices);
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (auto& num: prices)
        {
            for (int i = 1; i <= k; i++)
            {
                buy[i] = max(buy[i], sell[i - 1] - num);
                sell[i] = max(sell[i], buy[i] + num);
            }
        }
        return sell[k];
    }

};
// @lc code=end

int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    Solution s;
    s.maxProfit(2, prices);
    cout << s.naiveProfit(prices) << endl;
    return 0;
}