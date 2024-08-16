/*
Title: Gas Station
Link: https://leetcode.com/problems/gas-station/
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalRemGas = 0;
        int tank = 0;

        int output = 0;

        for(int i = 0; i < n; i++){
            totalRemGas += gas[i] - cost[i];
            tank += gas[i] - cost[i];

            if(tank < 0){
                tank = 0;
                output = i+1;
            }
        }

        return totalRemGas < 0 ? -1 : output;
    }
};
