/*
Title: Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

// Breadth First Search Approach
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;

        if(!root){
            return output;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int> level;
            while(size > 0){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

                level.push_back(temp->val);
                size--;
            }

            output.push_back(level);
        }

        return output;   
    }
};
