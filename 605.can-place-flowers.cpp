/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */
#include "vector"
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) return 0;
        int res = 0;
        for (int i = 0; i < flowerbed.size(); i++) 
        {
            if (flowerbed[i] == 1) continue;
            bool empty_left = (i == 0) || flowerbed[i - 1] == 0;
            bool empty_right = (i == flowerbed.size() - 1 ) || flowerbed[i + 1] == 0;
            if (empty_left && empty_right)
            {
                res += 1;
                i += 1;
            }
        }
        return res >= n;
    }
};
// @lc code=end

