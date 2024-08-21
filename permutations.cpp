/*
Title: Permutations
Link: https://leetcode.com/problems/permutations/
*/

// Using backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;

        vector<int> tempList;
        backtrack(output, tempList, nums);

        return output;
    }

    void backtrack(vector<vector<int>> &output, vector<int> &tempList, vector<int> &nums){
        if(tempList.size() == nums.size()){
            output.push_back(tempList);
            return;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                if(count(tempList.begin(), tempList.end(), nums[i]) > 0){
                    continue;
                }

                tempList.push_back(nums[i]);
                backtrack(output, tempList, nums);
                tempList.pop_back();
            }
        }
    }
};
