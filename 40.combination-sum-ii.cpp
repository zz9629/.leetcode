/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    map<int, int> lastIndex;

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
            int pos = max(i, lastIndex[nums[i]]);
            backtrace(nums, temp, result, pos + 1, remain - nums[i]);
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++)
        {
            lastIndex[candidates[i]] = i;
        }
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(candidates, temp, res, 0, target);
        return res;
    }
   
};
// @lc code=end

