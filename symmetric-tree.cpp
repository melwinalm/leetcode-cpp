/*
Title: Symmetric Tree
Link: https://leetcode.com/problems/symmetric-tree/
*/

// Recursive 
class Solution {
private:
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        else if(left == NULL || right == NULL){
            return false;
        }

        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};
