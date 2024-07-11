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

// Using Topological Sorting
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        // Forming adjacency list along with indegree count
        for(vector<int> edge: edges){
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);

            indegree[a]++;
            indegree[b]++;
        }

        queue<int> q;
        
        // Push all the nodes with indegree 1 to the queue since they will be the leaf nodes and leaf nodes can't form the minimum height tree
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }

        vector<int> output;

        while(!q.empty()){
            int count = q.size();

            // If the queue is not empty then clear output since there is still a better answer with even lesser height
            output.clear();

            // Loop through all the leaf nodes and check the neighbours of those whose degree is 1
            while(count > 0){
                int curr = q.front();
                q.pop();

                output.push_back(curr);

                for(int edge: adj[curr]){
                    indegree[edge]--;

                    if(indegree[edge] == 1){
                        q.push(edge);
                    }
                }

                count--;
            }

        }

        return output;
    }
};
