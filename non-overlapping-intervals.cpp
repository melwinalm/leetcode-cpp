/*
Title: Non-overlapping Intervals
Link: https://leetcode.com/problems/non-overlapping-intervals
*/

// Sort the array in ascending order of end times
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1){
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });

        int output = 0;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < n; i++){
            int tempStart = intervals[i][0];
            int tempEnd = intervals[i][1];

            if(tempStart >= end){
                start = tempStart;
                end = tempEnd;
            }
            else{
                output++;
            }
        }

        return output;
    }
};
