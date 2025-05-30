/*
Title: Insert into a Binary Search Tree
Link: https://leetcode.com/problems/insert-into-a-binary-search-tree
*/

// Iterative Approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL){
            return newNode;
        }

        TreeNode* current = root;
        TreeNode* parent = NULL;

        while(current != NULL){
            parent = current;
            if(val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }

        if(val < parent->val){
            parent->left = newNode;
        }
        else{
            parent->right = newNode;
        }

        return root;
    }
};

// Recursive Approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        else if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        else{
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
