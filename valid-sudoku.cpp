/*
Title: Valid Sudoku
Link: https://leetcode.com/problems/valid-sudoku
*/

class Solution {
private:
    bool isRowsValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }

                if(set.find(board[i][j]) == set.end()){
                    set.insert(board[i][j]);
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }

    bool isColumnsValid(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.'){
                    continue;
                }

                if(set.find(board[j][i]) == set.end()){
                    set.insert(board[j][i]);
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }

    bool isBoxValid(vector<vector<char>>& board){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                unordered_set<char> set;
                for(int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        int temp = board[(3 * i) + a][(3 * j) + b];

                        if(temp == '.'){
                            continue;
                        }

                        if(set.find(temp) == set.end()){
                            set.insert(temp);
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }


public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isRowsValid(board) && isColumnsValid(board) && isBoxValid(board);
    }
};
