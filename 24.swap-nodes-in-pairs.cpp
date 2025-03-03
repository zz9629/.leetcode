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
    ListNode* swapPairs(ListNode* head) {
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

};
// @lc code=end

