/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

/*
    We have to do so in :

    R1. Linear Time
    R2. Using Constant Space

    METHOD 1 : USING MAPS (NOT USING CONSTANT SPACE )
    METHOD 2 : USING SORTING (USING CONSTANT SPACE ) TC: O(NlogN), SC: O(1)
    METHOD 3 : USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )
*/

// @lc code=start
#include <functional>
#include <numeric>
#include <unordered_map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        std::unordered_map<int, int> map;
        for (auto& num: nums)
        {
            if (map.find(num) == map.end())
                map[num]++;
            else 
            {
                map.erase(num);
            }
        }
        for (auto& item: map)
        {
            return item.first;
        }
        return -1;
        */

        int result = 0;
        for (auto& num: nums){
            result ^= num;
        }
        return result;

        // equals
        // return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};
// @lc code=end

