/*
Title: Subsets
Link: https://leetcode.com/problems/subsets/
*/

// Using Backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;

        vector<int> tempList;
        backtrack(output, tempList, nums, 0);

        return output;
    }

    void backtrack(vector<vector<int>> &output, vector<int> &tempList, vector<int> &nums, int start){
        output.push_back(tempList);

        for(int i = start; i < nums.size(); i++){
            tempList.push_back(nums[i]);
            backtrack(output, tempList, nums, i+1);
            tempList.pop_back();
        }
    }
};
