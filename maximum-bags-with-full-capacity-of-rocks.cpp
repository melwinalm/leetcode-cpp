/*
Title: Maximum Bags With Full Capacity of Rocks
Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0;
        int n = size(capacity);
        vector<int> diff(n);

        for(int i = 0; i < size(capacity); i++){
            diff[i] = capacity[i] - rocks[i];
        }

        sort(diff.begin(), diff.end());

        for(int i = 0; i < n; i++){
            if(additionalRocks >= diff[i]){
                count++;
                additionalRocks -= diff[i];
            }
            else{
                break;
            }
        }

        return count;
    }
};
