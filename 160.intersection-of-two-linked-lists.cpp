/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
public:
    // Time Complexity : O(m + n)
    // Space Complexity : O(m)
    ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        std::unordered_map<ListNode*, bool> isVisted;
        auto tailA = headA;
        while (tailA)
        {
            isVisted[tailA] = true;
            tailA = tailA->next;
        }   
        auto tailB = headB;
        while (tailB)
        {
            if (isVisted[tailB]) return tailB;
            tailB = tailB->next;
        }
        return nullptr;
    }

    // better idea
    ListNode *getIntersectionNode__(ListNode *headA, ListNode *headB) {
        auto l1 = headA, l2 = headB;
        while (l1 != l2)
        {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

    }

};
// @lc code=end

