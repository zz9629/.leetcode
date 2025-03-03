/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
#include <vector>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if (slow != fast) return nullptr;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *detectCycle_(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode* slow = head, *fast = head->next;
        while (slow && fast)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast) return nullptr;

        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> tmp{1,2};
    ListNode *head = new ListNode(1); // Instantiate a ListNode object and assign it to the head pointer
    s.detectCycle(head);
    return 0;
}
