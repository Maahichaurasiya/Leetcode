/*
Approach:
- The diameter of a binary tree is the length of the longest path between any
two nodes.
- For every node, there are three possible cases:
    1. The diameter lies entirely in the left subtree.
    2. The diameter lies entirely in the right subtree.
    3. The diameter passes through the current node.
- To find the diameter passing through the current node, calculate the heights
of its left and right subtrees.
- The current diameter is:
      leftHeight + rightHeight
- Recursively compute the diameters of the left and right subtrees and return
the maximum among: leftDiameter, rightDiameter, and currentDiameter.
- The height function recursively returns the maximum height of the left and
right subtrees plus one.
- Since the height is recomputed for every node, this brute-force approach has a
time complexity of O(n²).
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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        int currDia = height(root->left) + height(root->right);

        return max(max(leftDia, rightDia), currDia);
    }
};