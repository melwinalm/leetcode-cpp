/*
Title: Validate Binary Search Tree
Link: https://leetcode.com/problems/validate-binary-search-tree
*/

// Recursive Solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }

    bool validate(TreeNode* root, TreeNode* minval, TreeNode* maxval){
        if(root == NULL){
            return true;
        }

        if((minval == NULL || root->val > minval->val) && (maxval == NULL || root->val < maxval->val)){
            return validate(root->left, minval, root) && validate(root->right, root, maxval);
        }

        return false;
    }
};
