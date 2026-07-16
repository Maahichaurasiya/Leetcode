/*
Approach:
- The problem is solved using two recursive functions:
  1. isIdentical() checks whether two binary trees are exactly the same.
  2. isSubtree() traverses the main tree and checks if any node can be the root
     of a subtree identical to subRoot.
- For every node in the main tree, compare its value with the root of subRoot.
- If the values match, use isIdentical() to verify whether both trees are
  structurally identical and contain the same node values.
- If they are identical, return true.
- Otherwise, recursively search for subRoot in the left and right subtrees.

Algorithm:
1. If either tree is NULL, return whether both are NULL.
2. Traverse each node of the main tree.
3. Whenever the current node's value matches subRoot's value:
   - Call isIdentical() to compare both trees.
4. If isIdentical() returns true, subRoot exists in the main tree.
5. Otherwise, continue searching recursively in the left and right subtrees.
6. If no matching subtree is found, return false.

Time Complexity: O(n × m)
- n = number of nodes in the main tree.
- m = number of nodes in subRoot.
- In the worst case, isIdentical() may be called for every node in the main
tree.

Space Complexity: O(h1 + h2)
- h1 = height of the main tree.
- h2 = height of subRoot.
- The recursive call stack depends on the heights of both trees.
- Worst Case: O(n + m) for skewed trees.
- Best/Average Case: O(log n + log m) for balanced trees.
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
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        return isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right) && (p->val == q->val);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }
        if (root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};