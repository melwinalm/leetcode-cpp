/*
Title: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int temp = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(temp == nums[i]){
                return true;
            }
            else{
                temp = nums[i];
            }
        }

        return false;
    }
};
