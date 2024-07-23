/*
Title: Is Subsequence
Link: https://leetcode.com/problems/is-subsequence
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        int tIndex = 0;

        while(sIndex < s.size() && tIndex < t.size()){
            if(s[sIndex] == t[tIndex]){
                sIndex++;
                tIndex++;
            }
            else{
                tIndex++;
            }
        }

        return sIndex == s.size();
    }
};
