/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* removeNthFromEnd_(ListNode* head, int n) {
        if (!head) return head;
        
        auto fast = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) // 删除头节点
        {
            auto next = head->next;
            delete head;
            return next;
        }

        auto slow = head;
        while (fast->next)
        {
            // pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        auto del = slow->next;
        slow->next = slow->next->next;
        delete del; // 这里应该不需要判断空指针

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

    }

};
// @lc code=end

