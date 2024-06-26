/*
Title: Binary Tree Right Side View
Link: https://leetcode.com/problems/binary-tree-right-side-view/
*/

//Breadth First Search
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        
        if(!root){
            return output;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int count = q.size();

            while(count > 0){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

                if(count == 1){
                    output.push_back(temp->val);
                }

                count--;
            }
        }

        return output;
    }
};
