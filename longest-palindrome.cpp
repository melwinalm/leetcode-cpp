/*
Title: Longest Palindrome
Link: https://leetcode.com/problems/longest-palindrome/
*/
// Using Hashmap
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mapper;

        for(char c: s){
            if(mapper.find(c) != mapper.end()){
                mapper[c]++;
            }
            else{
                mapper[c] = 1;
            }
        }

        bool oddFlag = false;
        int result = 0;

        for(auto item: mapper){
            if(item.second % 2 == 0){
                result += item.second;
            }
            else{
                result += (item.second / 2) * 2;
                oddFlag = true;
            }
        }

        if(oddFlag){
            result++;
        }

        return result;
    }
};
