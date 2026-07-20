/*
Approach:

* The first element in preorder is always the root of the current subtree.
* Find this root value in the inorder array.
* Elements to the left of the root in inorder belong to the left subtree.
* Elements to the right of the root in inorder belong to the right subtree.
* Recursively build the left and right subtrees using these boundaries.

Working:

1. Create a root node using preorder[preIdx].
2. Find the index of this root in the inorder array.
3. Increment preIdx to move to the next root in preorder.
4. Recursively build the left subtree using inorder[left ... inIdx-1].
5. Recursively build the right subtree using inorder[inIdx+1 ... right].
6. Return the constructed root node.

Time Complexity: O(n²) in the worst case, because we linearly search the inorder
array for each node. Space Complexity: O(h), where h is the height of the tree
due to recursion stack.
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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                     int left, int right) {
        if (left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};