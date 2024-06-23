/*
Title: Find the Minimum Area to Cover All Ones I
Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i
*/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();
        
        int left = INT_MAX;
        int right = INT_MIN;
        int top = INT_MAX;
        int down = INT_MIN;
        
        for(int i = 0; i < rowCount; i++){
            for(int j = 0; j < colCount; j++){
                if(grid[i][j] == 1){
                    left = min(left, i);
                    right = max(right, i);
                    top = min(top, j);
                    down = max(down, j);
                }
            }
        }

        return (right - left + 1) * (down - top + 1);
    }
};
