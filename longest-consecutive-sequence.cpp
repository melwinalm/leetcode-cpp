/*
Title: Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int output = 0;

        for(int start: s){
            if(s.find(start-1) == s.end()){
                int end = start + 1;

                while(s.find(end) != s.end()){
                    end++;
                }

                output = max(output, end - start);
            }
        }

        return output;
    }
};
