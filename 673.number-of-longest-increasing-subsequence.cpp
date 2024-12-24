/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> len(n + 1, 1);
        vector<int> count(n + 1, 1);  // stores count of longest sequence of length lis[i]
        len[0] = 0, len[1] = 1;
        int max_len = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (nums[i - 1] > nums[j - 1]) {
                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if (len[i] == len[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            max_len = max(max_len, len[i]);
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if(len[i] == max_len) result += count[i];
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1 ,3, 5, 4, 7, 7, 8};
    cout <<  s.findNumberOfLIS(nums) << endl;
}
