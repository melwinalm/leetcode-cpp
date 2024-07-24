/*
Title: Maximum Units on a Truck
Link: https://leetcode.com/problems/maximum-units-on-a-truck
*/

// Greedy Approach
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });

        int maxUnits = 0;
        int i = 0;
        while(truckSize > 0 && i < boxTypes.size()){
            int numOfBoxes = boxTypes[i][0];
            int numOfUnits = boxTypes[i][1];

            int boxesTaken = min(truckSize, numOfBoxes);

            maxUnits += (boxesTaken * numOfUnits);
            truckSize -= boxesTaken;
            i++;
        }

        return maxUnits;
    }
};
