/*
Title: Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes
*/
// Using O(m+n) space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> M(m, 1);
        std::vector<int> N(n, 1);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    M[i] = 0;
                    N[j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(M[i] == 0 || N[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
