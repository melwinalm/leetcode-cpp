/*
Title: Lowest Common Ancestor of a Binary Search Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
        while(root != NULL){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            else{
                break;
            }
        }

        return root;
    }
};
