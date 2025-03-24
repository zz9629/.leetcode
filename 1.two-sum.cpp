/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
#include <vector>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        // force algo
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                return {i, map[target - nums[i]]};
            }
            map[nums[i]] = i;
        }

        return res;
    }
};
// @lc code=end
