/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */
 
#include <vector>
#include "iostream"
using namespace std;

// @lc code=start
class Solution {
public:
    int find_max(vector<int>& arr, int left, int right)
    {
        if (left > right) return -1;
        if (right >= arr.size()) return -1;
        int res = arr[left];
        for (int i = left + 1; i <= right; i++)
        {
            res = max(res, arr[i]);
        }
        return res;
    } 

    // 适用于任意初始值的递增数组, 如排列后为[2, ..., n]
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (arr.empty()) return 0;
        int res = 0;
        int start_pos = 0;
        int end_pos = 0;
        while (start_pos < n)
        {
            res++;
            int max_val = arr[start_pos]; // 合法再取值
            for (int i = start_pos + 1; i < n; i++)
            {
                // 如果小于当前窗口内的最大值
                if (arr[i] < max_val)
                {
                    end_pos = i;
                    // 更新最大值
                    max_val = find_max(arr, start_pos, end_pos);
                    // max_val = max(max_val, arr[i]);
                }
            }

            start_pos = end_pos + 1;
            end_pos = start_pos;
            // max_val = arr[start_pos]; // 这里下标可能不合法
        }

        return res;
    }

    // 仅针对值从0-n的数组，如排列后为[0, 1, 2, ..., n]
    int maxChunksToSorted__(vector<int>& arr) {
        int res = 0;
        int cur = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cur = max(cur, arr[i]);
            if (cur == i) res++;
        }
        return res;
    }

    // int maxChunksToSorted___(vector<int>& arr) {
    
    // }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums = {1,4,0,2,3,5}; // expected: 2
    cout << s.maxChunksToSorted(nums);
    return 0;
}