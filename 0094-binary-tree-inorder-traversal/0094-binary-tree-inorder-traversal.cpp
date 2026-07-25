
/*
Approach:
---------
This solution uses Morris Inorder Traversal to perform an inorder traversal
of the binary tree without using recursion or an extra stack.

Normally, inorder traversal requires either:
1. Recursion (uses call stack), or
2. An explicit stack.

Morris Traversal avoids both by temporarily modifying the tree.
It creates a temporary link (called a thread) from the Inorder
Predecessor of a node back to the current node. This allows us
to return to the current node after completely visiting its left
subtree.

Before the traversal finishes, all temporary threads are removed,
so the original tree structure remains unchanged.

Algorithm:
----------
1. Start from the root node.
2. While the current node is not NULL:
   - If there is no left child:
       • Visit the current node.
       • Move to its right child.
   - Otherwise:
       • Find the Inorder Predecessor (the rightmost node in the left subtree).
       • If the predecessor's right pointer is NULL:
            - Create a temporary thread pointing to the current node.
            - Move to the left child.
       • Otherwise:
            - The left subtree has already been visited.
            - Remove the temporary thread.
            - Visit the current node.
            - Move to the right child.
3. Repeat until all nodes are processed.

Example:
--------

        4
       / \
      2   6
     / \ / \
    1  3 5  7

Traversal Process:

Start at 4
↓
Move to left subtree after creating a thread.

Visit 1
Answer = [1]

Return to 2 using the thread.
Visit 2
Answer = [1, 2]

Visit 3
Answer = [1, 2, 3]

Return to 4 using the thread.
Visit 4
Answer = [1, 2, 3, 4]

Move to right subtree.

Visit 5
Answer = [1, 2, 3, 4, 5]

Visit 6
Answer = [1, 2, 3, 4, 5, 6]

Visit 7
Answer = [1, 2, 3, 4, 5, 6, 7]

Final Output:
-------------
[1, 2, 3, 4, 5, 6, 7]

Time Complexity:
----------------
O(n)

Each node is processed at most twice:
- Once while creating a temporary thread.
- Once while removing the thread.

Therefore, the overall time complexity is O(n).

Space Complexity:
-----------------
O(1)

No recursion or stack is used.
Only a few pointers (curr and predecessor) are maintained,
making the extra space constant.

Why Morris Traversal?
---------------------
- Eliminates the need for recursion.
- Does not require an auxiliary stack.
- Uses only constant extra space.
- Restores the original binary tree after traversal.
- Preferred when an inorder traversal with O(1) auxiliary space is required.
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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{

                // finding IP (Inorder Predecessor is rightmost node of left subTree)
                TreeNode* IP=curr->left;
                while(IP->right!=NULL && IP->right!=curr){
                    IP=IP->right;
                }
                if(IP->right==NULL){
                    IP->right=curr; //create thread
                    curr=curr->left;
                }
                else{
                    IP->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};