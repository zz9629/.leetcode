/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    // recursive
    ListNode* swapPairs_(ListNode* head) {
        if (!head || !head->next) return head;
        auto temp = head->next;
        auto next = head->next->next;

        temp->next = head;
        head->next = swapPairs(next);

        return temp;
    }

    // non-recursive
    ListNode* swapPairs__(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;

        while (head && head->next)
        {
            auto temp = head->next;
            auto next = temp->next;

            pre->next = temp;
            temp->next = head; 
            head->next = next;

            pre = head;
            head = next;
        }

        return dummy->next;
    }

    ListNode* swapPairs(ListNode* head) {
        // pre, node1 -> node2 -> node2 
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head, *pre = dummy;
        while (cur && cur->next)
        {
            auto next = cur->next->next;
            auto temp = cur->next;

            pre->next = temp;
            temp->next = cur;
            cur->next = next;

            pre = cur;
            cur = next;
        }
        return dummy->next;
    }

};
// @lc code=end

