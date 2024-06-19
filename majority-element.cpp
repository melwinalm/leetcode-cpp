/*
Title: Majority Element
Link: https://leetcode.com/problems/majority-element
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums[0];
        }

        sort(nums.begin(), nums.end());

        int result = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == result){
                count++;
            }
            else{
                if(count > nums.size()/2){
                    break;
                }
                result = nums[i];
                count = 1;
            }
        }

        return result;
    }
};
