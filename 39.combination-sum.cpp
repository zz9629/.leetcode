/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    
    /* dp不行，不会去重
    input [2,3,6,7], 7
    output [[3,2,2],[2,3,2],[2,2,3],[7]]
    Expected Answer [[2,2,3],[7]]
    */
    vector<vector<int>> combinationSum_(vector<int>& candidates, int target) {
        // 完全背包，价值在外正向，物品在内
        map<int, vector<vector<int>> > dp;
        // vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
        dp[0] = vector<vector<int>>();

        for (int i = 2; i <= target; i++)
        {
            for (auto & num: candidates)
            {
                if (i >= num)
                {
                    if (dp.count(i - num))
                    {
                        if (dp[i - num].empty())
                        {
                            vector<int> temp = {num};
                            dp[i].push_back(temp);
                        }
                        for (auto vec: dp[i - num])
                        {
                            dp[i].push_back(vec);
                            dp[i].back().push_back(num);
                        }
                    }
                }
            }
        }
        return dp[target];
    }
    
    void backtrace(vector<int>& nums, vector<int>& temp,  vector<vector<int>>& result,  int start, int remain)
    {
        if (remain < 0) return;
        if (0 == remain) 
        {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrace(nums, temp, result, i, remain - nums[i]);
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(candidates, temp, res, 0, target);
        return res;
    }

};
// @lc code=end

