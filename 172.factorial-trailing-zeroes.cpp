/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes_(int n) {
        // 递归
        // if (n == 0) return 0; // 注意终止条件，否则会infinite loop
        // return trailingZeroes(n / 5) + n / 5;

        // 非递归
        int result = 0;
        while (n)
        {
            result += n / 5;
            n = n / 5;
        }
        return result;




    }

    int trailingZeroes(int n) {
        int res = 0;
        while (n)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }

};
// @lc code=end

