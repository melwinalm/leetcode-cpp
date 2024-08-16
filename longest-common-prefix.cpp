/*
Title: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(n == 1){
            return strs[0];
        }
        
        string output = "";
        string curr = strs[0];

        for(int i = 0; i < curr.size(); i++){
            bool flag = true;
            for(int j = 1; j < n; j++){
                if(i < strs[j].size() && strs[j][i] == curr[i]){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }

            if(flag){
                output += curr[i];
            }
            else{
                break;
            }
        }

        return output;
    }
};
