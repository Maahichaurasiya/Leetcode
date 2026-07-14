/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




 /*
Approach: Recursive Preorder Traversal

Preorder traversal follows the order:
    Root -> Left -> Right

Algorithm:
1. If the current node is NULL, return.
2. Visit the current node and store its value.
3. Recursively traverse the left subtree.
4. Recursively traverse the right subtree.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to the recursive call stack.
- Worst case: O(n) (skewed tree)
- Best/Average case: O(log n) (balanced tree)
*/



class Solution {
public:
    vector<int>ans;
    void preOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};