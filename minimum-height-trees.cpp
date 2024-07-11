/*
Title: Minimum Height Trees
Link: https://leetcode.com/problems/minimum-height-trees
*/

// Using Naive Approach (TLE error)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(vector<int> edge: edges){
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> heights(n);

        for(int i = 0; i < n; i++){
            unordered_set<int> visited;
            heights[i] = maxHeight(adj, visited, i);
        }

        int minHeight = INT_MAX;

        for(int i = 0; i < n; i++){
            minHeight = min(minHeight, heights[i]);
        }

        vector<int> output;

        for(int i = 0; i < n; i++){
            if(heights[i] == minHeight){
                output.push_back(i);
            }
        }

        return output;
    }

    int maxHeight(unordered_map<int, vector<int>>& adj, unordered_set<int> visited, int node){
        if(visited.find(node) != visited.end()){
            return 0;
        }

        visited.insert(node);

        int maxSoFar = 0;
        for(int edge: adj[node]){
            maxSoFar = max(maxSoFar, 1 + maxHeight(adj, visited, edge));
        }

        return maxSoFar;
    }
};
