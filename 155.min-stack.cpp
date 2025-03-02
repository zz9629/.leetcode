/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include "stack"
using namespace std;

// @lc code=start

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        if (min_.empty() || min_.top() >= val)
        {
            min_.push(val);
        }
        data.push(val);
    }

    void pop() {
        if (data.empty()) return;
        if (min_.top() == data.top())
        {
            min_.pop();
        }
        data.pop();
    }

    int top() {
        if (data.empty()) return -1;
        return data.top();
    }

    int getMin() {
        if (min_.empty()) return -1;
        return min_.top();
    }

    stack<int> data;
    stack<int> min_;
};

/*
class MinStack_ {
public:
    MinStack() {

    }
    
    void push(int val) {
        pair<int, int> item{val, min_val};
        if (val < min_val) 
        {
            min_val = val;
        }
        data.push(item);
    }
    
    void pop() {
        auto topData = data.top();
        if (min_val == topData.first)
        {
            min_val = topData.second;
        }
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    
    int getMin() {
        return min_val;
    }

    stack<pair<int, int>> data; // value, last_min
    int min_val = INT_MAX;
};

*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

