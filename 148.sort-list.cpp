/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (!list1) return list2;
            if (!list2) return list1;
            ListNode* dummy = new ListNode(-1);
    
            ListNode* cur = dummy;
            while (list1 && list2)
            {
                if (list1->val <= list2->val)
                {
                    cur->next = list1;
                    list1 = list1->next;
                }
                else 
                {
                    cur->next = list2;
                    list2 = list2->next;
                }
                cur = cur->next;
            }
            cur->next = list1 ? list1 : list2;
    
            cur = dummy->next;
            delete dummy;
            return cur;
        }
    
    
        ListNode* sortList_(ListNode* head) {
            if(!head || !head->next) return head;
            if (!head->next->next)
            {
                auto next = head->next;
                if (head->val < next->val) return head;
                next->next = head;
                head->next = nullptr;
                return next;
            }
            auto slow = head;
            auto fast = head;
            auto temp = head;
            while (fast && fast->next)
            {
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = nullptr;
            head = sortList(head);
            slow = sortList(slow);
            return mergeTwoLists(head, slow);
        }

        ListNode* sortList(ListNode* head) {
            
        }

    };
// @lc code=end

