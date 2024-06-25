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

// Breadth First Search
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        int depth = 0;
        while(!bfsQueue.empty()){
            int count = bfsQueue.size();
            depth++;
            while(count > 0){
                TreeNode* temp = bfsQueue.front();
                bfsQueue.pop();

                if(temp->left){
                    bfsQueue.push(temp->left);
                }
                if(temp->right){
                    bfsQueue.push(temp->right);
                }
                count--;
            }
        }

        return depth;
    }
};
