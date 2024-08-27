/*
Title: Combination Sum II
Link: https://leetcode.com/problems/combination-sum-ii/
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b){
            return a < b;
        });

        vector<vector<int>> output;
        vector<int> tempList;
        backtrack(output, tempList, candidates, 0, target);

        return output;
    }

    void backtrack(vector<vector<int>> &output, vector<int> &tempList, vector<int> &candidates, int i, int target){
        if(target == 0){
            output.push_back(tempList);
            return;
        }

        if (target < 0){
            return;
        }

        for(int a = i; a < candidates.size(); a++){
            if(i != a && candidates[a] == candidates[a-1]){
                continue;
            }
            tempList.push_back(candidates[a]);
            backtrack(output, tempList, candidates, a+1, target - candidates[a]);
            tempList.pop_back();
        }
    }
};
