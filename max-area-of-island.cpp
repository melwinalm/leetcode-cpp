/*
Title: Max Area of Island
Link: https://leetcode.com/problems/max-area-of-island/
*/

// Using Depth First search
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxSoFar = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int count = maxArea(grid, i, j, m, n);
                    cout << count << endl;
                    maxSoFar = max(maxSoFar, count);
                }
            }
        }

        return maxSoFar;
    }

    int maxArea(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0){
            return 0;
        }

        int count = 1;

        grid[i][j] = 0;

        count += maxArea(grid, i-1, j, m, n);
        count += maxArea(grid, i+1, j, m, n);
        count += maxArea(grid, i, j-1, m, n);
        count += maxArea(grid, i, j+1, m, n);

        return count;
    }
};
