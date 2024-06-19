/*
Title: Insert Interval
Link: https://leetcode.com/problems/insert-interval
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(vector<int>{newInterval[0], newInterval[1]});

        if(intervals.size() < 2){
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> vect1, vector<int> vect2){
            return vect1[0] < vect2[0];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> output;

        for(int i = 1; i < intervals.size(); i++){
            if(end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
            }
            else{
                output.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        output.push_back(vector<int>{start, end});

        return output;
    }
};
