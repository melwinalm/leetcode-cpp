/*
Title: House Robber
Link: https://leetcode.com/problems/house-robber/
*/

// Top Down Approach
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return rob(nums, dp, nums.size() - 1);
    }

    int rob(vector<int>& nums, vector<int>& dp, int i){
        if(i < 0){
            return 0;
        }

        if(dp[i] >= 0){
            return dp[i];
        }

        dp[i] = max(rob(nums, dp, i-2) + nums[i], rob(nums, dp, i-1));

        return dp[i];
    }
};
