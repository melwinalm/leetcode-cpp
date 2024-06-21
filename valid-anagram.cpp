/*
Title: Valid Anagram
Link: https://leetcode.com/problems/valid-anagram
*/

// Using frequency calculation using static array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int val: freq){
            if(val != 0){
                return false;
            }
        }

        return true;
    }
};

// Using string sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        sort(s.begin(), s.end(), [](char c1, char c2){
            return c1 < c2;
        });

        sort(t.begin(), t.end(), [](char c1, char c2){
            return c1 < c2;
        });

        return s == t;
    }
};
