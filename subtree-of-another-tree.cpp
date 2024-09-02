/*
Title: Subtree of Another Tree
Link: https://leetcode.com/problems/subtree-of-another-tree
*/

class Solution {
private:
    bool isSametree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            return isSametree(root->left, subRoot->left) && isSametree(root->right, subRoot->right);
        }
        else{
            return false;
        }
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }

        if(isSametree(root, subRoot)){
            return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
