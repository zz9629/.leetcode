/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include "vector"
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        int result = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end){
                result += 1;
            }
            else {
                end = intervals[i][1];
            }
        }
        return result;
    }
};
// @lc code=end

