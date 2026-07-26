/*
Approach:
---------
The given array is already sorted, so we use the middle element as the root.
This keeps the Binary Search Tree (BST) balanced.

Algorithm:
----------
1. If the current range is invalid (st > end), return NULL.
2. Find the middle index of the current array.
3. Create a new node using the middle element.
4. Recursively build the left subtree using the left half.
5. Recursively build the right subtree using the right half.
6. Return the root node.

Why Middle Element?
-------------------
- Elements before the middle are smaller, so they form the left subtree.
- Elements after the middle are larger, so they form the right subtree.
- Choosing the middle element keeps the tree height balanced.

Example:
--------
nums = [-10, -3, 0, 5, 9]

          0
        /   \
     -10     5
       \      \
       -3      9

Time Complexity:
----------------
O(n)
- Every element is used once to create a node.

Space Complexity:
-----------------
O(log n)
- Recursive call stack for a balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) {
            return NULL;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};