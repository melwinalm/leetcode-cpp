/*
Title: Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters
*/
// Using set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();

        if(N < 2){
            return N;
        }

        int maxSoFar = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> set;

        while(i < N && j < N){
            if(set.find(s[j]) != set.end()){
                set.erase(s[i]);
                i++;
            }
            else {
                set.insert(s[j]);
                maxSoFar = max(maxSoFar, j - i + 1);
                j++;
            }
        }

        return maxSoFar;
    }
};
