/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include "stack"
using namespace std;

// @lc code=start
class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        trans();
        int top = b.top();
        b.pop();
        return top;
    }
    
    int peek() {
        trans();
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }

private:
    void trans()
    {
        if(!b.empty()) 
        {
            return;
        }
        while (!a.empty())
        {
            int top = a.top();
            a.pop();
            b.push(top);
        }
    }   

private:
    stack<int> a;
    stack<int> b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

