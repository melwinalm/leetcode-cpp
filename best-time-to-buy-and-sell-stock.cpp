/*
Title: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestSoFar = prices[0];
        int maxSoFar = 0;

        for(int i = 1; i < prices.size(); i++){
            lowestSoFar = min(lowestSoFar, prices[i]);
            maxSoFar = max(maxSoFar, prices[i] - lowestSoFar);
        }

        return maxSoFar;
    }
};
