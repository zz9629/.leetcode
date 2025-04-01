/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        auto dummyLess = new ListNode(0);
        auto dummyGreater = new ListNode(0);
        auto left = dummyLess;
        auto right = dummyGreater;
        while (head)
        {
            if (head->val < x)
            {
                left->next = head;
                left = left->next;
            }
            else 
            {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        // 这里要断开
        right->next = nullptr;

        left->next = dummyGreater->next;
        delete dummyGreater;
        auto ret = dummyLess->next;
        delete dummyLess;
        return ret;
    }
};
// @lc code=end

