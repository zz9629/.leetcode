/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
#include "unordered_map"
#include "vector"
using namespace std;

// 1. https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
// 2. 
/* 
So the idea is similar as Two sum, 
using HashMap to store ( key : the prefix sum, value : how many ways get to this prefix sum) , 
and whenever reach a node, we check if prefix sum - target exists in hashmap or not, 
    if it does, we added up the ways of prefix sum - target into res.

So, suppose we have an array as arr[]: [1,2,3,4,5] and k = 9

so, our answer will be '2' i.e (2 + 3 + 4 and 4 + 5)
so if we store our prefix sum array then it should looks like:
index :   0, 1, 2, 3,  4
  arr[]: [1, 2, 3, 4,  5]
prefix[]:[1, 3, 6, 10, 15]
          ↑         ↑
prefix[]:[1, 3, 6, 10, 15]
                ↑       ↑
How, we will find our subarray (2 + 3 + 4) using prefix sum, see-


*/

// @lc code=start
class Solution {
public:
    int subarraySum__(vector<int>& nums, int k) {
        int n = nums.size(); 
        int sum = 0;
        // unordered_map to store prefix sums frequencies
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            // Add current element to sum so far.
            sum += nums[i];

            // If currSum is equal to desired sum, then a new
            // subarray is found. So increase count of subarrays.
            if (sum == k) res++;

            // Check if the difference exists in the prefixSums map.
            if (map.find(sum - k) != map.end())
            {
                res += map[sum - k];
            }

            // Add currSum to the set of prefix sums.
            map[sum]++;
        }
        return res;
    }

    // more concise
    int subarraySum_(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        int sum = 0, result = 0;
        map[sum] = 1;
        
        for (int n : nums) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
        
        return result;
    }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0;
        int result = 0;
        map[0] = 1;
        for (auto& item: nums)
        {
            sum += item;
            result += map[sum - k];
            map[sum]++;
        }
        return result;
    }

};
// @lc code=end

