/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

 #include "vector"
#include <cmath>
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
    // Memory Limit Exceeded
    ListNode* oddEvenList__(ListNode* head) {
        std::vector<ListNode*> odd, even;
        auto cur = head;
        while (cur)
        {
            odd.push_back(cur);
            if (cur->next)
            {
                even.push_back(cur->next);
                cur = cur->next->next;
            }
        }

        cur = head;
        for (int i = 1; i < odd.size(); i++)
        {
            cur->next = odd[i];
            cur = cur->next;
        }
        for (int i = 0; i < even.size(); i++)
        {
            cur->next = even[i];
            cur = cur->next;
        }
        return head;
    }

    ListNode* oddEvenList_(ListNode* head) {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }
        auto odd = head;
        auto even = head->next;
        auto even_start = even;
        // 注意odd和even的先后顺序
        while (odd->next && even->next)
        {
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;
        return head;
    }


    
    ListNode* oddEvenList(ListNode* head) {
        
    }

};
// @lc code=end

