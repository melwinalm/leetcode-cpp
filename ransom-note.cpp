/*
Title: Ransom Note
Link: https://leetcode.com/problems/ransom-note/
*/

// Using Hashmap
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()){
            return false;
        }

        unordered_map<char,int> freq;

        for(char c: magazine){
            if(freq.find(c) != freq.end()){
                freq[c]++;
            }
            else{
                freq[c] = 1;
            }
        }

        for(char c: ransomNote){
            if(freq.find(c) == freq.end()){
                return false;
            }
            else{
                if(freq[c] == 1){
                    freq.erase(c);
                }
                else{
                    freq[c]--;
                }
            }
        }

        return true;
    }
};
