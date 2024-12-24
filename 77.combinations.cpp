/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    void backTrace(int n, int k, int level, int pos, vector<int>& temp, vector<vector<int> >& results) 
    {   
        if (level == k) 
        {
            results.push_back(temp);
            return;
        }
        // 当前选取的数字，从pos开始选
        for (int i = pos; i <= n; i++)
        {
            temp[level] = i; // 加入结果
            level ++;
            backTrace(n, k, level, i + 1, temp, results); 
            level--;        // 从结果中取出来
        }

    }

    vector<vector<int> > combine_(int n, int k) {
        vector<vector<int> > results;
        vector<int> temp(k, 0);
        backTrace(n, k, 0, 1, temp, results);
        return results;
    }

        void traceBack(vector<vector<int> >& result, vector<int>& nums,
                    int n, int k, int pos, int level)
    {   
        if (level == k)
        {
            result.push_back(nums);
            return;
        }
        for (int i = pos; i <= n; i++)
        {
            nums[level] = i;
            traceBack(result, nums, n, k, i + 1, level + 1);
            level--;
        }
    }

    vector<vector<int> > combine_(int n, int k) {
        vector<vector<int> > result;
        vector<int> nums(k, 0);
        traceBack(result, nums, n, k, 1, 0);
        return result;
    }
};
// @lc code=end

int main()
{
    int n = 4, k = 2;
    Solution s;
    auto result = s.combine(n, k);

    return 0;
}
