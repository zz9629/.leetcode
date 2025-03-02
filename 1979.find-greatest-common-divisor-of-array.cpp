/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */
 #include "vector"
using namespace std;
// @lc code=start
class Solution {
public:
    int findGCD_(vector<int>& nums) {
        int a = nums[0];
        int b = nums[0];
        for (auto& num: nums)
        {
            a = max(a, num);
            b = min(b, num);
        }
        while (a != b)
        {
            if (a > b) a = a - b;
            else b = b - a;
        }

        return a;
    }


    int gcd(int a, int b)
    {
        // while (a != b)
        // {
        //     if (a > b) a = a - b;
        //     else b = b - a;
        // }
        // return a;

        // 
        return b == 0 ? a : gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int a = nums[0];
        int b = a;
        for (auto & num: nums)
        {
            a = max(a, num);
            b = min(b, num);
        }
        
        return gcd(a, b);
    }

};
// @lc code=end

