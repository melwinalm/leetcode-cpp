/*
Title: Lowest Common Ancestor of a Binary Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pTraversal;
        stack<TreeNode*> qTraversal;

        traversalPath(root, p->val, pTraversal);
        traversalPath(root, q->val, qTraversal);

        TreeNode* output = root;

        int psize = pTraversal.size();
        int qsize = qTraversal.size();

        int i = min(psize, qsize);

        while(i > 0){
            if(pTraversal.top() == qTraversal.top()){
                output = pTraversal.top();
                pTraversal.pop();
                qTraversal.pop();
            }
            else{
                break;
            }

            i--;
        }

        return output;
    }

    bool traversalPath(TreeNode* curr, int target, stack<TreeNode*>& path){
        if(!curr){
            return false;
        }

        if(curr->val == target){
            return true;
        }

        if(traversalPath(curr->left, target, path)){
            path.push(curr->left);
            return true;
        }

        if(traversalPath(curr->right, target, path)){
            path.push(curr->right);
            return true;
        }

        return false;
    }
};
