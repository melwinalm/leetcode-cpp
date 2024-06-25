/*
Title: Balanced Binary Tree
Link: https://leetcode.com/problems/balanced-binary-tree/
*/

// Depth First Search
class Solution {
public:
    bool isbalanced = true;
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        depth(root);

        return isbalanced;
    }

    int depth(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);

        if(abs(left - right) > 1){
            isbalanced = false;
            return -1;
        }

        return 1 + max(left, right);
    }
};
