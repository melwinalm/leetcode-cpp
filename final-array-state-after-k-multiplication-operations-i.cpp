/*
Title: Final Array State After K Multiplication Operations I
Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
*/

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        
        while(k > 0){
            int smallestIndex = 0;
            int smallestNum = nums[0];
            for(int i = 1; i < n; i++){
                if(nums[i] < smallestNum){
                    smallestNum = nums[i];
                    smallestIndex = i;
                }
            }

            nums[smallestIndex] *= multiplier;

            k--;
        }

        return nums;
    }
};
