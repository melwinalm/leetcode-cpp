/*
Title: Binary Tree Preorder Traversal
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

class Solution {
public:
    vector<int> output;
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);    

        return output;
    }

    void preorder(TreeNode* root){
        if(!root){
            return;
        }

        output.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};
