/*
Title: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
*/

// Using Set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> duplicate;

        for(int val : nums){
            if(duplicate.find(val) != duplicate.end()){
                return true;
            }
            else{
                duplicate.insert(val);
            }
        }

        return false;
    }
};

// Using Sorting
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
