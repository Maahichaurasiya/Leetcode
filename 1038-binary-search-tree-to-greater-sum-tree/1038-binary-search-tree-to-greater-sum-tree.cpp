/*
Approach:
- We convert the Binary Search Tree (BST) into a Greater Sum Tree (GST).
- In a GST, each node contains the sum of all node values greater than or equal
  to the current node's value.

Key Observation:
- In a BST, inorder traversal (Left -> Root -> Right) visits nodes in ascending
order.
- Therefore, reverse inorder traversal (Right -> Root -> Left) visits nodes in
  descending order, from largest to smallest.

Algorithm:
1. Traverse the right subtree first because it contains larger values.
2. Maintain a global variable 'sum' to store the running total of visited nodes.
3. Add the current node's value to 'sum'.
4. Update the current node's value with the running 'sum'.
5. Traverse the left subtree.

Why no leftSum/rightSum is needed:
- The recursive function does not return subtree sums.
- Instead, the global variable 'sum' continuously stores the sum of all
  previously visited greater nodes.
- Hence, we only update 'sum' during reverse inorder traversal.

Time Complexity: O(n)
- Each node is visited exactly once during the traversal.

Space Complexity: O(h)
- h is the height of the tree due to the recursion stack.
- Worst case (skewed tree): O(n)
- Best/Average case (balanced tree): O(log n)
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
    int sum = 0;
    void sumTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // right subtree
        sumTree(root->right);
        sum += root->val;
        root->val = sum;

        // left subtree
        sumTree(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sumTree(root);
        return root;
    }
};