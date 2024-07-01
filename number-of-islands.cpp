/*
Title: Number of Islands
Link: https://leetcode.com/problems/number-of-islands/
*/

// Using Depth First Search
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == '0'){
            return;
        }

        int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
        grid[i][j] = '0';

        for(auto move: moves){
            int newI = i + move[0];
            int newJ = j + move[1];

            dfs(grid, newI, newJ, m, n);
        }
    }
};
