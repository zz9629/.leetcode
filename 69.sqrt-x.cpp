/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 1, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int sqrt = x / mid;
            if (sqrt == mid) return mid;
            else if (sqrt < mid) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};
// @lc code=end

