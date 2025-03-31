/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <unordered_set>
#include <vector>
using namespace std;
#include <unordered_map>

// @lc code=start
class Solution {
public:
    void helper(vector<int>& nums, int fixIndex, int target, unordered_set<vector<int>>& res)
    {
        // 2 sum, equals target
        // std::unordered_map<int, vector<int>> map;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if ( i == fixIndex) continue;
        //     if (map.find(target - nums[i]) != map.end())
        //     {
        //         vector<int> temp;
        //         temp.push_back(nums[fixIndex]);
        //         temp.push_back(nums[i]);

        //         auto vec = map[target - nums[i]];
        //         for (auto& index: vec)
        //         {
        //             temp.push_back(nums[index]);
        //             res.insert(temp);
        //             temp.pop_back();
        //         }
        //     }
        //     map[nums[i]].push_back(i);
        // }
    }

    // {
    //             // unordered_set<vector<int>> res;
    //     // for (int i = 0; i < nums.size(); i++)
    //     // {
    //     //     helper(nums, i, 0 - nums[i], res);
    //     // }
    //     // vector<vector<int>> vec(res.begin(), res.end());
    //     // return vec;
    // }

    vector<vector<int>> threeSum_(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3 || nums[0] > 0) return res;
        
        //Hashing of Indices, 更新到最后一次出现的index
        unordered_map<int , int> map;
        for (int i = 0; i < n; i++) 
        {
            map[nums[i]] = i;
        }
        //Traversing the array to fix the number.
        for (int i = 0; i < n - 2; i++) 
        {
            //If number fixed is +ve, stop there because we can't make it zero by searching after it.
            if (nums[i] > 0) break; 
            for (int j = i + 1; j < n - 1; j++) 
            {
                int target = -nums[i] - nums[j];
                //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                if (map.count(target) && map[target] > j)
                {
                    res.push_back({nums[i], nums[j], target});
                }
                //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
                j = map.find(nums[j])->second;
            }
             //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
            i = map.find(nums[i])->second;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }

        if (nums.size() < 3 || nums[0] > 0) return res;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0) break;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int target = -nums[i] - nums[j];
                if (map.count(target) && map[target] > j)
                {
                    res.push_back({nums[i], nums[j], target});
                }
                j = map[nums[j]];
            }
            i = map[nums[i]];
        }
        return res;
    }

};
// @lc code=end


int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    auto res = s.threeSum(nums);
    return 0;
}