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
