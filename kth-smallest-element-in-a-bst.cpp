/*
Title: Kth Smallest Element in a BST
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

// Recursive Approach
class Solution {
    int count = 0;
    int output = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        smallest(root);
        return output;
    }

    void smallest(TreeNode* root){
        if(root->left != NULL){
            smallest(root->left);
        }

        count--;
        if(count == 0){
            output = root->val;
        }

        if(root->right != NULL){
            smallest(root->right);
        }
    }
};
