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

// LeetCode 112: Path Sum
// Approach: DFS + Recursion
//
// Goal:
// Check if there exists a root-to-leaf path
// whose sum is equal to targetSum.
//
// 1. If root == NULL:
//    No path exists -> return false.
//
// 2. If current node is a leaf:
//    Check whether root->val == targetSum.
//    If equal -> valid path found.
//
// 3. Otherwise:
//    Explore both left and right subtrees.
//    Subtract current node's value from targetSum
//    before moving to the child.
//
// 4. Use OR (||):
//    If either left or right subtree has a valid path,
//    return true.
//
// Key Idea:
// Instead of calculating the path sum,
// keep reducing the remaining target.
//
// Example:
// Target = 22
// Path = 5 -> 4 -> 11 -> 2
//
// 22 - 5  = 17
// 17 - 4  = 13
// 13 - 11 = 2
// 2 == 2 -> true
//
// Time Complexity: O(N)
// Space Complexity: O(H)
// N = number of nodes
// H = height of the tree

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val == targetSum;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};