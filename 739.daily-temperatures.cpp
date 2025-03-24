/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include "stack"
#include "vector"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures_(vector<int>& temperatures) {
        stack<int> indices;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!indices.empty())
            {
                auto topIndex = indices.top();
                // 注意是等号，要处理重复元素，也放入递减栈，说明还没有碰到更高的温度
                if (temperatures[topIndex] >= temperatures[i])
                {
                    // 可以入栈了，break
                    break;
                }
                // 否则pop，topindex的有答案了
                indices.pop();
                res[topIndex] = i - topIndex;
            }

            indices.push(i);
        }

        return res;
    }



    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> cache;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!cache.empty())
            {
                auto lastIndex = cache.top();
                if (temperatures[i] <= temperatures[lastIndex]) 
                {
                    break;
                }
                cache.pop();
                result[lastIndex] = i - lastIndex;
            }

            cache.push(i);
        }
    
        return result;
    }

};
// @lc code=end

