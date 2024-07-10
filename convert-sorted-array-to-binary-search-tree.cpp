/*
Title: Convert Sorted Array to Binary Search Tree
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
*/

// Recursive Solution
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size()-1);
    }

    TreeNode* createBST(vector<int>& nums, int start, int end){
        int mid = (start + end)/ 2;

        TreeNode* midNode = new TreeNode(nums[mid]);

        if(start != end){
            if(start < mid){
                midNode->left = createBST(nums, start, mid-1);
            }

            if(mid < end){
                midNode->right = createBST(nums, mid+1, end);
            }
        }

        return midNode;
    }
};
