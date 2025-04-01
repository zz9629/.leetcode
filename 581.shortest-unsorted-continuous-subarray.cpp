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
        int start = -1, end = -1;
        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            max_val = max(max_val, nums[i]);
            if (nums[i] < max_val)
            {
                end = i;
            }
        }

        int min_val = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            min_val = min(min_val, nums[i]);
            if (nums[i] > min_val)
            {
                start = i;
            }
        }

        return start >= end ? 0 : end - start + 1;
        // return end - start + 1;
    }
};

// @lc code=end

