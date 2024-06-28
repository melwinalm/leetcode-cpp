/*
Title: Find Center of Star Graph
Link: https://leetcode.com/problems/find-center-of-star-graph/
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> set;

        int u1 = edges[0][0];
        int v1 = edges[0][1];

        int u2 = edges[1][0];
        int v2 = edges[1][1];

        set.insert(u1);
        set.insert(v1);

        if(set.find(u2) != set.end()){
            return u2;
        }

        if(set.find(v2) != set.end()){
            return v2;
        }

        return 0;
    }
};
