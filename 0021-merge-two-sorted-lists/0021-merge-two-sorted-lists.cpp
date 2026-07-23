/**
 * LeetCode 21 - Merge Two Sorted Lists
 *
 * Approach:
 * - Use recursion to merge two sorted linked lists.
 * - Compare the current nodes of both lists:
 *      • If h1->val <= h2->val, choose h1 as the next node
 *        and recursively merge h1->next with h2.
 *      • Otherwise, choose h2 as the next node
 *        and recursively merge h2->next with h1.
 * - Continue this process until one of the lists becomes NULL.
 *
 * Base Case:
 * - If one list is empty, return the other list directly,
 *   because it is already sorted.
 *
 * Recursive Flow:
 * Example:
 * h1: 1 -> 3 -> 5
 * h2: 2 -> 4 -> 6
 *
 * 1 is smaller than 2, so 1 is chosen first.
 * Then merge:
 *      3 -> 5
 *      2 -> 4 -> 6
 *
 * This repeats recursively until all nodes are merged into
 * a single sorted linked list:
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Time Complexity: O(n + m)
 * - Each node from both lists is visited exactly once.
 *
 * Space Complexity: O(n + m)
 * - Recursive calls use stack space proportional to the total
 *   number of nodes in both lists.
 */

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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {

        if (h1 == NULL || h2 == NULL) {
            return h1 == NULL ? h2 : h1;
        }

        if (h1->val <= h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        }

        else {
            h2->next = mergeTwoLists(h2->next, h1);
            return h2;
        }
    }
};