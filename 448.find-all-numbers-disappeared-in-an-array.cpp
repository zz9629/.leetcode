/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
#include "vector"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers_(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<vector<int>> buckets(n + 1, vector<int>());
        for (auto & num: nums)
        {
            buckets[num].push_back(num);
        }
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (buckets[i].empty()) res.push_back(i);
        }

        return res;
        */
        vector<int> count(n + 1, 0);
        for (auto & num: nums)
        {
            count[num]++;
        }
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (count[i] == 0) res.push_back(i);
        }
        return res;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
    }

};
// @lc code=end

