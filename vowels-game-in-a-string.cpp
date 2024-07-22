/*
Title: Vowels Game in a String
Link: https://leetcode.com/problems/vowels-game-in-a-string
*/

// If there's a vowel in the string, then alice wins
class Solution {
public:
    bool doesAliceWin(string s) {
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                return true;
            }
        }

        return false;
    }
};
