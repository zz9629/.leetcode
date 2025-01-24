/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include "queue"
using namespace std;

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
    ListNode* merge(ListNode* & a, ListNode* & b)
    {
        if (!a && !b) return nullptr;
        if (!a) return b;
        if (!b) return a;
        
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        while (a && b)
        {
            if (a->val <= b->val)
            {
                dummyTail->next = a;
                a = a->next;
            }
            else 
            {
                dummyTail->next = b;
                b = b->next;
            }
            dummyTail = dummyTail->next;
        }
        dummyTail->next = a ? a : b;
        return dummyHead->next;
        /*
        ListNode* headA = a;
        ListNode* headB = b;

        ListNode* i = a;
        ListNode* j = b;
        while (i && j)
        {
            if (i->val <= j->val)
            {
                auto nextNode = i->next;
                i->next = j;
                i = nextNode;
            }
            else 
            {
                auto nextNode = j->next;
                j->next = i;
                j = nextNode;
            }
        }

        return headA->val <= headB->val ? headA : headB;
        */
    }

    ListNode* mergeHelper(vector<ListNode*>& lists, int left, int right)
    {
        if (left > right) return nullptr;
        if (left == right) return lists[left];
        int mid = left + (right - left) / 2;
        auto leftList = mergeHelper(lists, left, mid);
        auto rightList = mergeHelper(lists, mid + 1, right);
        return merge(leftList, rightList);
    }

    struct com
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // return mergeHelper(lists, 0, lists.size() - 1);

        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, com> pq;
        for (auto& l : lists)
        {   
            if (l) pq.push(l);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (!pq.empty())
        {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next)
            {
                pq.push(cur->next);
            }

        }

        ListNode *dummyNext = dummy->next;
        delete dummy;
        return dummyNext;
    }
};
// @lc code=end

