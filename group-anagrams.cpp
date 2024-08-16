/*
Title: Group Anagrams
Link: https://leetcode.com/problems/group-anagrams
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string str: strs){
            string copy = str;
            sort(copy.begin(), copy.end());

            if(map.find(copy) == map.end()){
                map[copy] = vector<string>();
            }
            
            map[copy].push_back(str);
            
        }

       vector<vector<string>> output;

        for(auto item: map){
            output.push_back(item.second);
        }

        return output;
    }
};
