/*
Title: Minimum Length of String After Operations
Link: https://leetcode.com/problems/minimum-length-of-string-after-operations
*/

// Greedy Solution
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> map;

        for(char c: s){
            map[c]++;
        }

        int output = 0;
        for(auto c: map){
            int count = c.second;

            if(count >= 3){
                count = count % 2 == 0 ? 2 : 1;
            }

            output += count;
        }

        return output;
    }
};
