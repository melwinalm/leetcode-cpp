/*
Title: Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray
*/

// Using Dynamic Programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }

        int output = dp[0];

        for(int i = 1; i < n; i++){
            output = max(output, dp[i]);
        }

        return output;
    }
};

// Using Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        int maxSoFar = nums[0];
        int currSum = nums[0];

        for(int i = 1; i < n; i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSoFar = max(maxSoFar, currSum);
        }

        return maxSoFar;
    }
};
