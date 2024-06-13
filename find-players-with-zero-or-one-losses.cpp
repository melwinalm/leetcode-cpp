/*
Title: Find Players with Zero or One Losses
Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> map;

        for(int i = 0; i < matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            map.insert({winner, 0});
            map.insert({loser, 0});
        }

        for(int i = 0; i < matches.size(); i++){
            int loser = matches[i][1];

            map[loser] += 1;
        }

        vector<int> answer0;
        vector<int> answer1;

        for(auto item: map){
            if(item.second == 0){
                answer0.push_back(item.first);
            }
            else if(item.second == 1){
                answer1.push_back(item.first);
            }
        }

        return vector<vector<int>> {answer0, answer1};
    }
};
