/**
 *
 * Approach:
 * We use Inorder Traversal (Left -> Root -> Right) because inorder traversal
 * of a Binary Search Tree (BST) visits nodes in sorted order.
 *
 * Since the values are sorted during inorder traversal, the minimum
 * absolute difference will always be between two adjacent nodes
 * in this sorted sequence.
 *
 * Steps:
 * 1. Perform inorder traversal of the BST.
 * 2. Keep track of the previously visited node using the variable `prev`.
 * 3. For each current node, calculate the difference:
 *      current node value - previous node value
 * 4. Update `minDiff` with the smallest difference found so far.
 * 5. Return `minDiff` after the traversal is complete.
 *
 * Example:
 * Input BST:
 *        4
 *       / \
 *      2   6
 *     / \
 *    1   3
 *
 * Inorder Traversal: [1, 2, 3, 4, 6]
 * Adjacent Differences: [1, 1, 1, 2]
 * Minimum Difference = 1
 *
 * Time Complexity: O(N)
 * - Each node is visited exactly once during inorder traversal.
 *
 * Space Complexity: O(H)
 * - H is the height of the tree due to the recursion stack.
 * - In the worst case of a skewed tree, H = N.
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
    int minDiff = INT_MAX;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {

        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;

        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};