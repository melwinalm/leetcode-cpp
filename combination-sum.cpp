/*
Title: Conbination Sum
Link: https://leetcode.com/problems/combination-sum/
*/

// Backtracking Approach
class Solution {

private:
    void combinationSum(vector<int>& candidates, int target, int index, vector<vector<int>>& output, vector<int>& temp){
        if(target < 0){
            return;
        }

        if(target == 0){
            output.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, output, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<vector<int>> output;    
        vector<int> temp;

        combinationSum(candidates, target, 0, output, temp);

        return output;
    }
};
