/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
// @lc code=start
class Solution {
public:
    void backtrace(vector<int>& nums, int level, vector<vector<int> >& results)
    {
        if (level == nums.size() - 1)
        {
            results.push_back(nums);
            return;
        } 
        for (int i = level; i < nums.size(); i++)
        {
            swap(nums[level], nums[i]);
            backtrace(nums, level + 1, results);
            swap(nums[level], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > results;
        backtrace(nums, 0, results);
    }
};
// @lc code=end

int main()
{
    // vector<vector<vector<int> > > testCases;
    // testCases.push_back(vector<vector<int> > ({{0, 1}, {1,0}}));
    // testCases.push_back(vector<vector<int> > ({{1, 1}, {0,1}}));
    Solution s;
    auto area = s.permute({1, 2, 3});
}