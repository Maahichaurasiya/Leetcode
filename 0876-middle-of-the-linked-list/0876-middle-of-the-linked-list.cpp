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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Approach: Slow & Fast Pointer
//
// slow moves 1 step at a time
// fast moves 2 steps at a time
//
// When fast reaches the end,
// slow will be at the middle.
//
// For even length, return the SECOND middle node.
//
// Example:
// 1 -> 2 -> 3 -> 4 -> 5
//              ↑
//            slow
// Answer = 3
//
// Example:
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
//              ↑
//            slow
// Answer = 4 (second middle)
//
// Time Complexity: O(n)
// Space Complexity: O(1)