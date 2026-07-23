/**
 * LeetCode 662 - Maximum Width of Binary Tree
 *
 * Approach:
 * - Use Breadth-First Search (BFS) / Level Order Traversal.
 * - Store each node along with its index, similar to how a binary tree
 *   is represented in an array.
 * - For a node at index i:
 *      Left child  -> 2 * i + 1
 *      Right child -> 2 * i + 2
 * - For every level, calculate the width using:
 *      width = lastIndex - firstIndex + 1
 * - Keep track of the maximum width among all levels.
 *
 * Why use indices?
 * - Indices help account for null gaps between nodes, ensuring the width
 *   is calculated correctly even when the tree is sparse.
 *
 * Example:
 *        1
 *       / \
 *      3   2
 *     /     \
 *    5       9
 *
 * Indices:
 * 1 -> 0
 * 3 -> 1, 2 -> 2
 * 5 -> 3, 9 -> 6
 *
 * Width of last level = 6 - 3 + 1 = 4
 *
 * Time Complexity: O(n)
 * - Each node is visited exactly once.
 *
 * Space Complexity: O(n)
 * - In the worst case, the queue stores all nodes of the widest level.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (q.size() > 0) {
            int size = q.size(); // curr level size
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth, int(endIdx - stIdx + 1));

            for (int i = 0; i < size; i++) {
                auto currNode = q.front();
                q.pop();

                if (currNode.first->left) {
                    q.push({currNode.first->left, currNode.second * 2 + 1});
                }

                if (currNode.first->right) {
                    q.push({currNode.first->right, currNode.second * 2 + 2});
                }
            }
        }
        return maxWidth;
    }
};