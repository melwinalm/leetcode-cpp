/*
Title: Snake in Matrix
Link: https://leetcode.com/problems/snake-in-matrix/
*/

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;

        for(string command: commands){
            if(command == "LEFT"){
                x--;
            }
            else if(command == "RIGHT"){
                x++;
            }
            else if(command == "UP"){
                y--;
            }
            else if(command == "DOWN"){
                y++;
            }
        }

        return (y * n) + x;
    }
};
