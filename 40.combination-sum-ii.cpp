/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <map>
#include <vector>

 using namespace std;
// @lc code=start
class Solution {
public:

    /*
    input [10,1,2,7,6,1,5], 8
    排序后 [1, 1, 2, 5, 6, 7, 10]
    Output [[1,1,6],[1,2,5],[1,7],[2,6]]
    重点是只会生成一个[1,2,5] 而不是两个[1, 2, 5]
    */
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
            // 应该是：在同一层for循环时，如果发现重复元素，跳过；而不是在选完元素后跳过。
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            
            /*
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
            你在 选完一个数 (temp.push_back(nums[i])) 后立刻跳过了所有重复的数（while (nums[i+1] == nums[i]) i++）。
            这样做会漏掉一些必须用到重复数的情况，比如 1 + 1 + 6 = 8。
            */
            backtrace(nums, temp, result, i + 1, remain - nums[i]);
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrace(candidates, temp, res, 0, target);
        return res;
    }
   
};
// @lc code=end

int main()
{
    vector<int> nums = {10,1,2,7,6,1,5};
    Solution s;
    auto res = s.combinationSum2(nums, 8);

    return 0;

}