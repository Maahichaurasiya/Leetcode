/*
Approach:
- The problem asks us to find the level (1-indexed) that has the maximum sum of
node values.
- We use Breadth-First Search (BFS) or Level Order Traversal since it processes
the tree level by level.
- A queue is used to store the nodes of the current level.
- For each level:
    1. Calculate the sum of all node values.
    2. Compare the current level's sum with the maximum sum found so far.
    3. If the current sum is greater, update the maximum sum and store the
current level.
- Continue until all levels have been processed.
- Finally, return the level number with the maximum sum.
- If multiple levels have the same maximum sum, the first (smallest) level is
returned because we update the answer only when a strictly greater sum is found.

Algorithm:
1. Push the root node into a queue.
2. Initialize:
      - level = 1
      - ansLevel = 1
      - maxSum = INT_MIN
3. While the queue is not empty:
      - Determine the number of nodes in the current level.
      - Traverse all nodes of that level and calculate their sum.
      - Push the left and right children into the queue.
      - If the current level's sum is greater than maxSum,
        update maxSum and ansLevel.
      - Move to the next level.
4. Return ansLevel.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- In the worst case, the queue stores all nodes of one level.
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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int level = 1;
        int ansLevel = 1;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
};