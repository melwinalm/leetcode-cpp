/*
Title: Best Time to Buy and Sell Stock II
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
*/

// Greedy Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n < 2){
            return 0;
        }

        int maxProfit = 0;
        int currMin = prices[0];

        for(int i = 1; i < n; i++){
            if(prices[i] > currMin){
                maxProfit += prices[i] - currMin;
                currMin = prices[i];
            }
            else{
                currMin = prices[i];
            }
        }

        return maxProfit;
    }
};
