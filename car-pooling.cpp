// Link: https://leetcode.com/problems/car-pooling

// Naive Approach
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxDistance = 0;

        vector<int> cap(1000+1);

        for(vector<int> trip: trips){
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            for(int i = from; i < to; i++){
                cap[i] += numPassengers;

                if(cap[i] > capacity){
                    return false;
                }
            }
        }

        return true;
    }
};
