/**

* Approach: Recursive Lowest Common Ancestor (LCA) in a Binary Tree
*
* The Lowest Common Ancestor of two nodes p and q is the lowest node
* in the tree that has both p and q as descendants (where a node can
* be a descendant of itself).
*
* How this recursive solution works:
* 1. Base Case:
* * If the current node (root) is NULL, return NULL because no node exists.
* * If the current node is either p or q, return the current node because
* ```
   we have found one of the target nodes.
  ```
*
* 2. Recursive Search:
* * Recursively search for p and q in the left subtree.
* * Recursively search for p and q in the right subtree.
*
* 3. Determine the LCA:
* * If both left and right recursive calls return non-NULL values, it means
* ```
   p and q were found in different subtrees, so the current node is their LCA.
  ```
* * If only one side returns non-NULL, return that side because both nodes
* ```
   are located in the same subtree.
  ```
* * If both sides return NULL, return NULL.
*
* Time Complexity: O(N)
* * Each node is visited at most once.
*
* Space Complexity: O(H)
* * Due to the recursion stack, where H is the height of the tree.
* * In the worst case (skewed tree), H can be N.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA && rightLCA) {
            return root;
        } else if (leftLCA != NULL) {
            return leftLCA;
        } else {
            return rightLCA;
        }
    }
};