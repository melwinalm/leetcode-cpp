/*
Title: Invert Binary Tree
Link: https://leetcode.com/problems/invert-binary-tree/
*/

// Recursive Solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        
        return root;
    }
};
