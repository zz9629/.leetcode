/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            auto sum = numbers[i] + numbers[j];
            if (target == sum) return {i+1, j+1};
            else if (target < sum) j--;
            else i++;
        }
        return {-1, -1};
    }
};
// @lc code=end

