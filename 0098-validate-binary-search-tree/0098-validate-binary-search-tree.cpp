/*
Idea:
-----
A Binary Search Tree (BST) is valid if:
1. Every node in the left subtree is smaller than the current node.
2. Every node in the right subtree is greater than the current node.

We use recursion and keep two limits for every node:
- min -> smallest value allowed
- max -> largest value allowed

How it works:
-------------
1. If the node is NULL, return true.
2. If node value is <= min, BST rule is broken.
3. If node value is >= max, BST rule is broken.
4. Check left subtree with:
      max = current node
5. Check right subtree with:
      min = current node

Example:
--------

        5
       / \
      3   7
     / \   \
    2   4   8

- For node 3, allowed range is (-inf, 5)
- For node 4, allowed range is (3, 5)
- For node 7, allowed range is (5, inf)

All nodes satisfy their ranges, so the tree is a valid BST.

Time Complexity:
----------------
O(n) -> each node is visited once.

Space Complexity:
-----------------
O(h) -> recursion stack, where h is the height of the tree.
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
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) {
            return true;
        }
        if (min != NULL && root->val <= min->val) {
            return false;
        }
        if (max != NULL && root->val >= max->val) {
            return false;
        }
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) { return helper(root, NULL, NULL); }
};