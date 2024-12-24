/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int findMax(vector<int>& arr, int left, int right){
        int res = arr[left];
        for (int i = left + 1; i <= right; i++) {
            res = max(res, arr[i]);
        }
        return res;
    }

    int helper(vector<int>& arr, int left, int right, vector<vector<int>>& memo){
        if (left >= right) return 0;
        if (left + 1 == right) return arr[left] * arr[right]; // not left * right
        if (memo[left][right] != -1) return memo[left][right];

        int res = INT_MAX;
        for (int mid = left; mid < right; mid++) {
            int sum = findMax(arr, left, mid) * findMax(arr, mid + 1, right) +
                    helper(arr, left, mid, memo) +  helper(arr, mid + 1, right, memo);
            res = min(res, sum);
        }
        memo[left][right] = res;
        return res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int> (n, - 1));
        return helper(arr, 0, n - 1, memo);
    }
};
// @lc code=end

