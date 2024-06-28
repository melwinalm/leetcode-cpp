/*
Title: Sum of Left Leaves
Link: https://leetcode.com/problems/sum-of-left-leaves/
*/

// Using Depth First Search
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, false);
    }

    int sum(TreeNode* root, bool isLeft){
        if(!root){
            return 0;
        }

        if(root->left == NULL && root->right == NULL && isLeft){
            return root->val;
        }

        return sum(root->left, true) + sum(root->right, false);
    }
};
