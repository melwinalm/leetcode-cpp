/*
Title: Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
*/

// Naive Approach
class Solution {
public:
    bool isPalindrome(string s) {
        string s2;

        for(char c: s){
            if(isalnum(c)){
                s2 += tolower(c);
            }
        }

        int N = s2.size();
        for(int i = 0; i < N; i++){
            if(s2[i] != s2[N-i-1]){
                return false;
            }
        }

        return true;
    }
};

// 
