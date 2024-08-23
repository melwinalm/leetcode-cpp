/*
Title: Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses
*/

// Using Backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, "", n, 0, 0);
        return output;
    }

    void backtrack(vector<string> &output, string tempString, int n, int openCount, int closeCount){
        if(tempString.size() == 2*n){
            output.push_back(tempString);
            return;
        }

        if(openCount < n){
            backtrack(output, tempString+'(', n, openCount+1, closeCount);
        }

        if(closeCount < openCount){
            backtrack(output, tempString+')', n, openCount, closeCount+1);
        }
    }
};
