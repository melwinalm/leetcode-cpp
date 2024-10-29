// Link: https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int output = 0;
        int curr = 0;

        for(int item : gain){
            curr += item;
            output = max(output, curr);
        }

        return output;
    }
};
