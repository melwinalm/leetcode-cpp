/*
Title: Maximum Energy Boost From Two Drinks
Link: https://leetcode.com/problems/maximum-energy-boost-from-two-drinks
*/

Using Dynamic Programming
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long n = energyDrinkA.size();

        vector<long long> dpA(n, 0);
        vector<long long> dpB(n, 0);

        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];

        for(long i = 1; i < n; i++){
            dpA[i] = max(dpA[i-1], i > 1 ? dpB[i-2] : 0) + energyDrinkA[i];
            dpB[i] = max(dpB[i-1], i > 1 ? dpA[i-2] : 0) + energyDrinkB[i];
        }

        return max(dpA[n-1], dpB[n-1]);
    }
};
