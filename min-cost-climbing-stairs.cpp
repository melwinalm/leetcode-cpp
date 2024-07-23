/*
Title: Min Cost Climbing Stairs
Link: https://leetcode.com/problems/min-cost-climbing-stairs
*/

// DP + Memoization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n == 2){
            return min(cost[0], cost[1]);
        }

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};

// Improved
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n == 2){
            return min(cost[0], cost[1]);
        }

        int prev = cost[0];
        int curr = cost[1];

        for(int i = 2; i < n; i++){
            int temp = cost[i] + min(prev, curr);
            prev = curr;
            curr = temp;
        }

        return min(prev, curr);
    }
};
