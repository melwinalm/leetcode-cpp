/*
Title: Range Sum Query 2D - Immutable
Link: https://leetcode.com/problems/range-sum-query-2d-immutable/
*/

// Using 2 Dimensional Prefix Sum
class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;

        this->prefixSum = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));

        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                this->prefixSum[i][j] = matrix[i-1][j-1] + this->prefixSum[i-1][j] + this->prefixSum[i][j-1] - this->prefixSum[i-1][j-1];
            }
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->prefixSum[row2+1][col2+1] - this->prefixSum[row2+1][col1] - this->prefixSum[row1][col2+1] + this->prefixSum[row1][col1]; 
    }
};
