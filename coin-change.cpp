/*
Title: Coin Change
Link: https://leetcode.com/problems/coin-change
*/

// DP Top Down Approach using Memoization (Uses unordered_map) (Time Limit Exceeded)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<string, int> map;
        
        int output = coinChange(coins, 0, amount, map);

        return output == INT_MAX - 1 ? -1 : output;
    }

    int coinChange(vector<int>& coins, int curr, int amount, unordered_map<string, int>& map){
        if(curr >= coins.size() || amount < 0){
            return INT_MAX - 1;
        }

        if(amount == 0){
            return 0;
        }

        string key = to_string(curr) + '$' + to_string(amount);

        if(map.find(key) != map.end()){
            return map[key];
        }

        int output = -1;

        if(coins[curr] > amount){
            int dontTakeCoin = coinChange(coins, curr+1, amount, map);
            output = dontTakeCoin;
        }
        else{
            int takeCoin = 1 + coinChange(coins, curr, amount - coins[curr], map);
            int dontTakeCoin = coinChange(coins, curr+1, amount, map);
            output = min(takeCoin, dontTakeCoin);
        }
        
        map[key] = output;

        return output;
    }
};

// DP Top Down Approach using Memoization (Uses static array)
class Solution {
public:
    int dp[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int output = coinChange(coins, 0, amount);

        return output == INT_MAX - 1 ? -1 : output;
    }

    int coinChange(vector<int>& coins, int curr, int amount){
        if(curr >= coins.size() || amount < 0){
            return INT_MAX - 1;
        }

        if(amount == 0){
            return 0;
        }

        if(dp[curr][amount] != -1){
            return dp[curr][amount];
        }

        int output = -1;

        if(coins[curr] > amount){
            int dontTakeCoin = coinChange(coins, curr+1, amount);
            output = dontTakeCoin;
        }
        else{
            int takeCoin = 1 + coinChange(coins, curr, amount - coins[curr]);
            int dontTakeCoin = coinChange(coins, curr+1, amount);
            output = min(takeCoin, dontTakeCoin);
        }
        
        dp[curr][amount] = output;

        return dp[curr][amount];
    }
};
