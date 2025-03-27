/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        // count k, get node;
        // pre, node1, node2, ... nodek, next
        //      cur,               end, next
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur)
        {
            // 找到第k个node
            ListNode* end = cur;
            for (int i = 1; i < k && end; i++) // 这里要注意end
            {
                end = end->next;
            }
            // 如果不足k，退出
            if (!end) break;

            // 记录next
            auto next = end->next;

            // 断开end链接，反转list
            end->next = nullptr;
            pre->next = reverseList(cur);
            cur->next = next;

            // move on
            pre = cur;
            cur = next;
        }
        return dummy->next;
    }
};
// @lc code=end

