class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int output = 0;
        int left = 0;

        unordered_map<char, int> map;

        for(char c: s){
            map[c]++;

            while(map[c] == k){
                map[s[left]]--;
                left++;
            }

            output += left;
        }

        return output;
    }
};
