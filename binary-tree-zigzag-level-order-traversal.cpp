/*
Title: Binary Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

// Using Breadth First Search
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;

        if(!root){
            return output;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int count = q.size();
            vector<int> level;

            for(int i = 0; i < count; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            flag = !flag;
            if(flag){
                reverse(level.begin(), level.end());
            }

            output.push_back(level);

        }

        return output;
    }
};
