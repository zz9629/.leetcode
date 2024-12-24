/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
#include <algorithm>
#include "vector"
using namespace std;

// @lc code=start
class Solution {
public:
    int findMinArrowShots_(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int arrow = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                arrow += 1;
                end = points[i][1];
            }
            end = min(end, points[i][1]); // update!
        }
        return arrow;
    }




    int findMinArrowShots(vector<vector<int> >& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        
        int end = points[0][1];
        int result = 1;
        for (auto& item: points)
        {
            if (item[0] <= end) 
            {
                end = min(end, item[1]);
            }
            else {
                result++;
                end = item[1];
            }
        }
        return result;
    }
};
// @lc code=end

