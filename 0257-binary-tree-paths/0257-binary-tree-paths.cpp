/**
 *
 * Approach:
 * Use Depth-First Search (DFS) with recursion to explore all
 * root-to-leaf paths in the binary tree.
 *
 * A path is built as a string while traversing from the root
 * to each node. When a leaf node is reached, the complete
 * path is added to the answer vector.
 *
 * Steps:
 * 1. Start the path string with the root node value.
 * 2. Recursively traverse the left subtree by appending
 *    "->" and the left child value.
 * 3. Recursively traverse the right subtree by appending
 *    "->" and the right child value.
 * 4. If the current node is a leaf node, store the path
 *    in the answer vector.
 *
 *
 * Time Complexity: O(N * L)
 * - N = number of nodes in the tree
 * - L = average length of the path string
 *
 * Space Complexity: O(H)
 * - H = height of the tree due to recursion stack
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
    void allPaths(TreeNode* root, string path, vector<string>& ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        if (root->left) {
            allPaths(root->left, path + "->" + to_string(root->left->val), ans);
        }

        if (root->right) {
            allPaths(root->right, path + "->" + to_string(root->right->val),
                     ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        allPaths(root, path, ans);
        return ans;
    }
};