/*
Title: Maximum Depth of Binary Tree
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

// Recursive appraoch
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
