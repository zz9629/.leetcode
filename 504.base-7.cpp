/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */
#include "string"
using namespace std;
// @lc code=start
class Solution {
public:
    // 递归
    string convertToBase7_(int num) {
        if (num < 0) return "-" + convertToBase7_(-num); // 这里要加一个“-”
        if (num < 7) return to_string(num);
        return convertToBase7_(num / 7) + to_string(num % 7);
    }

    // 非递归
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans; 
        bool isNeg = num < 0;
        if (isNeg) num = - num;
        while (num)
        {
            ans = to_string(num % 7) + ans;
            num = num / 7;
        }
        return isNeg? "-" + ans : ans;
    }


    string convertToBase7__(int num) {
   
    }

};
// @lc code=end

int main()
{
    Solution s;
    s.convertToBase7(100);
    return 0;
}