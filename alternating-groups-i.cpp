/*
Title: Alternating Groups I
Link: https://leetcode.com/problems/alternating-groups-i
*/

// Naive Solution
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();

        int output = 0;

        for(int i = 0; i < n; i++){
            if(i == 0){
                if(colors[n-1] != colors[i] && colors[i] != colors[i+1]){
                    output++;
                }
            }
            else if(i == n-1){
                if(colors[i-1] != colors[i] && colors[i] != colors[0]){
                    output++;
                }
            }
            else{
                if(colors[i-1] != colors[i] && colors[i] != colors[i+1]){
                    output++;
                }
            }
        }

        return output;
    }
};
