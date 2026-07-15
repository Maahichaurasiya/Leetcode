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



 /*
Approach:
- This solution uses the recursive Postorder Traversal technique.
- In postorder traversal, the nodes are visited in the following order:
  1. Traverse the left subtree.
  2. Traverse the right subtree.
  3. Visit the current node.
- A helper function `postorder()` is used to recursively visit each node.
- Every visited node's value is stored in the `ans` vector.
- Once the traversal is complete, the vector containing the postorder sequence is returned.

Algorithm:
1. If the current node is NULL, return.
2. Recursively traverse the left subtree.
3. Recursively traverse the right subtree.
4. Store the current node's value in the answer vector.
5. Return the final postorder traversal.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h is the height of the binary tree due to the recursive call stack.
- Worst Case: O(n) (Skewed Tree)
- Best/Average Case: O(log n) (Balanced Tree)
*/


class Solution {
public:
    vector<int> ans;
    void postOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {

        postOrder(root);
        return ans;
    }
};