/*
Approach (Optimized DFS):
- Instead of calculating the height separately for every node, compute both the
  height and diameter in a single DFS traversal.
- For each node:
    1. Recursively find the height of the left subtree.
    2. Recursively find the height of the right subtree.
    3. The diameter passing through the current node is:
           leftHeight + rightHeight
    4. Update the global variable 'ans' if the current diameter is larger than
       the previously recorded maximum.
- The height of the current node is:
       max(leftHeight, rightHeight) + 1
- After traversing the entire tree, 'ans' stores the maximum diameter of the
tree.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to the recursive call stack.
- Worst Case: O(n) for a skewed tree.
- Best/Average Case: O(log n) for a balanced tree.
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
    int ans = 0;
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        ans = max(ans, leftHeight + rightHeight); // currDia of root node

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
};