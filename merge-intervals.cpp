/*
Title: Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/solutions/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n < 2){
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> interval1, vector<int> interval2){
            return interval1[0] < interval2[0];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> output;

        for(int i = 1; i < n; i++){
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];

            if(newStart <= end){
                start = min(start, newStart);
                end = max(end, newEnd);
            }
            else{
                output.push_back(vector<int>{start, end});
                start = newStart;
                end = newEnd;
            }
        }

        output.push_back(vector<int>{start, end});

        return output;
    }
};
