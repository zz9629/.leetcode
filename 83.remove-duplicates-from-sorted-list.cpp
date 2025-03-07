/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

#include <cstddef>
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
    ListNode* deleteDuplicates_(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                auto del = cur->next;
                cur->next = cur->next->next;
                delete del;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
    }
};
// @lc code=end

