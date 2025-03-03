/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* helper(ListNode* head, ListNode* pre = nullptr)
    {
        auto next = head->next;
        head->next = pre;
        if (!next) return head;
        else return helper(next, head);
    }

    ListNode* reverseList_(ListNode* head) {
        if (!head || !head->next) return head;
        return helper(head);
    }

    // non-recursive
    ListNode* reverseList__(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = nullptr;
        while (head)
        {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }


    ListNode* reverseList(ListNode* head) {
        
        return nullptr;
    }

};
// @lc code=end

