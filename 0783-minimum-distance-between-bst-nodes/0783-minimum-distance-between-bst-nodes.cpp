/*
Approach:
---------
Since an inorder traversal of a Binary Search Tree (BST) visits nodes in
sorted order, the minimum difference will always be between two consecutive
nodes in this traversal.

We keep a pointer 'prev' to store the previously visited node.

How it works:
-------------
1. Perform an inorder traversal (Left -> Root -> Right).

2. Traverse the left subtree first.

3. When visiting the current node:
   - If 'prev' is not NULL, calculate the difference:
         current node value - previous node value
   - Update the minimum difference if this value is smaller.
   - Move 'prev' to the current node.

4. Traverse the right subtree.

5. Each recursive call returns the minimum difference found in its subtree.

Why Inorder?
------------
In a BST, inorder traversal gives the values in sorted order.

Example:
---------
        4
       / \
      2   6
     / \
    1   3

Inorder Traversal:
1 -> 2 -> 3 -> 4 -> 6

Differences:
2 - 1 = 1
3 - 2 = 1
4 - 3 = 1
6 - 4 = 2

Minimum Difference = 1

Time Complexity:
----------------
O(n)
Each node is visited exactly once.

Space Complexity:
-----------------
O(h)
where h is the height of the tree due to recursion.
- Balanced Tree: O(log n)
- Skewed Tree: O(n)
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
    TreeNode* prev = NULL;
    int minDist(TreeNode* root) {

        if (root == NULL) {
            return INT_MAX;
        }
        int ans = INT_MAX;
        if (root->left != NULL) {
            int leftMin = minDist(root->left);
            ans = min(ans, leftMin);
        }
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        if (root->right != NULL) {
            int rightMin = minDist(root->right);
            ans = min(ans, rightMin);
        }
        return ans;
    }

    int minDiffInBST(TreeNode* root) { return minDist(root); }
};