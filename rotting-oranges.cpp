/*
Title: Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges
*/

// Using Breadth First Search
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty() && fresh != 0){
            int count = q.size();

            while(count > 0){
                pair<int, int> temp = q.front();
                q.pop();

                int x = temp.first;
                int y = temp.second;

                for(auto move: moves){
                    int newI = x + move[0];
                    int newJ = y + move[1];

                    if(newI < 0 || newI >= m || newJ < 0 || newJ >= n || grid[newI][newJ] != 1){
                        continue;
                    }
                    
                    grid[newI][newJ] = 2;
                    fresh--;
                    q.push({newI, newJ});
                
                }
                
                count--;
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
