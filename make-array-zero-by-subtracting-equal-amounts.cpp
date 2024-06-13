/*
Title: Make Array Zero by Subtracting Equal Amounts
Link: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        unordered_set<int> set;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                set.insert(nums[i]);
            }
        }

        return size(set);
    }
};
