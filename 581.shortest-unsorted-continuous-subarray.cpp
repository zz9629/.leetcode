/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray_(vector<int>& nums) {
        int end = -1;
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxVal = max(maxVal, nums[i]); // 更新最大值
            // the left value is greater then current value
            if (nums[i] < maxVal) // mark that index with end
            {
                end = i;
            }
        }

        int start = nums.size();
        int minVal = nums[nums.size() - 1];
        for (int j = nums.size() - 2; j >= 0; j--)
        {
            minVal = min(minVal, nums[j]); // 更新最小值
            // the right value is smaller then current value
            if (nums[j] > minVal) // mark that index with start
            {
                start = j;
            }
        }

        return start >= end ? 0 : end - start + 1;
    }


    int findUnsortedSubarray(vector<int>& nums) {
        return 0;
    }
};

// @lc code=end

