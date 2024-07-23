/*
Title: Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;

        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            if(i == 0){
                temp = {1};
            }
            else if(i == 1){
                temp = {1, 1};
            }
            else{
                temp.push_back(1);

                for(int j = 0; j < output[i-1].size()-1; j++){
                    temp.push_back(output[i-1][j] + output[i-1][j+1]);
                }

                temp.push_back(1);
            }
            output.push_back(temp);
        }

        return output;
    }
};
