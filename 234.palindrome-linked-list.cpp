/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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

    ListNode* reverseList(ListNode* head) {
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

    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next)
        { 
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = fast ? reverseList(slow->next) : reverseList(slow);
        fast = head;
        while (fast && slow)
        {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

};
// @lc code=end

