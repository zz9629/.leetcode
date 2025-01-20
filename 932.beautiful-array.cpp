/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */
#include "vector"
using namespace std;
// @lc code=start
#include <unordered_map>
class Solution {
public:
    std::unordered_map<int, vector<int>> memo;

    vector<int> beautifulArray_tomDown(int n) {
        if (memo.find(n) != memo.end()) 
        {
            return memo[n];
        }

        vector<int> res;
        if (n == 1)
        {
            res.push_back(1);
            memo[n] = res;
            return res; 
        }
        else 
        {
            auto l = beautifulArray((n + 1) / 2);
            auto r = beautifulArray(n / 2);
            for (auto & item: l)
            {
                res.push_back(2 * item - 1);
            }
            for (auto & item: r)
            {
                res.push_back(2 * item);
            }

            memo[n] = res;
            return res;
        }
    }

    vector<int> beautifulArray_buttomUp(int n) {
        memo[1] = vector<int>{1};
        for (int i = 2; i <= n; i++)
        {
            vector<int> res;
            auto l = memo[(i + 1) / 2];
            auto r = memo[i / 2];
            for (auto & item: l)
            {
                res.push_back(2 * item - 1);
            }
            for (auto & item: r)
            {
                res.push_back(2 * item);
            }
            memo[i] = res;
        }

        return memo[n];    
    }

    vector<int> beautifulArray(int n) {
        
    }
};
// @lc code=end

