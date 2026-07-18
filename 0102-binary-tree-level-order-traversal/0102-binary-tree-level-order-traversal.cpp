/*
Approach:
- We use Breadth-First Search (BFS) or Level Order Traversal to visit the tree
level by level.
- A queue is used to process nodes in FIFO (First In, First Out) order.
- For each level:
    1. Store the number of nodes present in the current level.
    2. Traverse all those nodes and store their values in a temporary vector.
    3. Push their left and right children into the queue for the next level.
    4. Add the temporary vector to the final answer.
- Continue until the queue becomes empty.
- Finally, return the 2D vector containing all levels of the binary tree.

Algorithm:
1. If the tree is empty, return an empty vector.
2. Push the root node into the queue.
3. While the queue is not empty:
      - Find the number of nodes at the current level.
      - Create a vector to store the current level's values.
      - Remove each node from the queue, store its value, and push its children.
      - Add the current level vector to the answer.
4. Return the final 2D vector.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- The queue stores nodes level by level, and the answer vector stores all nodes.
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
    vector<vector<int>> ans;
    void levOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if (root == NULL) {
            return;
        }

        q.push(root);
        while (q.size() > 0) {
            vector<int> level;
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levOrder(root);
        return ans;
    }
};