/* Approach:

- The idea is to recursively compare the corresponding nodes of both binary
trees.
- If one node is NULL and the other is not, the trees are different.
- If both nodes are NULL, they are identical at that position.
- Otherwise, recursively compare the left subtrees and the right subtrees.
- Finally, check whether the current node values are equal.
- The trees are considered identical only if:
    1. Left subtrees are identical.
    2. Right subtrees are identical.
    3. Current node values are equal.

Algorithm:
1. Handle the base cases:
   - Return false if only one node is NULL.
   - Return true if both nodes are NULL.
2. Recursively compare the left children.
3. Recursively compare the right children.
4. Return true only if both recursive calls return true and the current node
values match.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to the recursive call stack.
- Worst Case: O(n) (skewed tree)
- Best/Average Case: O(log n) (balanced tree)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q != NULL) {
            return false;
        }
        if (p != NULL && q == NULL) {
            return false;
        }
        if (p == NULL && q == NULL) {
            return true;
        }

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && (p->val == q->val);
    }
};