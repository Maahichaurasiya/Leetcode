/*
Approach:
---------
The idea is to flatten the binary tree into a linked list in-place by using
Reverse Preorder Traversal (Right -> Left -> Root).

Normally, preorder traversal follows:
Root -> Left -> Right

Instead of creating a new list, we process the nodes in the reverse order.
This allows us to keep track of the previously visited node using the
'nextRight' pointer. Every current node is connected to this previously
processed node, gradually forming the required linked list.

How it Works:
-------------
1. First, recursively visit the right subtree.
2. Then, recursively visit the left subtree.
3. Remove the left child by setting left = NULL.
4. Connect the current node's right pointer to the previously processed node
   (stored in nextRight).
5. Update nextRight to the current node so it can be used for the next
connection.

Example:
--------

Original Tree:

        1
       / \
      2   5
     / \   \
    3   4   6

Processing Order (Reverse Preorder):
6 -> 5 -> 4 -> 3 -> 2 -> 1

Connections Created:
6 -> NULL
5 -> 6
4 -> 5
3 -> 4
2 -> 3
1 -> 2

Final Flattened Tree:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

Time Complexity:
----------------
O(n), because every node is visited exactly once.

Space Complexity:
-----------------
O(h), where h is the height of the tree due to the recursive call stack.

- Best Case (Balanced Tree): O(log n)
- Worst Case (Skewed Tree): O(n)
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
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};