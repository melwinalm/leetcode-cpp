/*
Title: Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int zeroPointer = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[zeroPointer] = nums[i];
                zeroPointer++;
            }
        }

        for(; zeroPointer < n; zeroPointer++){
            nums[zeroPointer] = 0;
        }
    }
};
