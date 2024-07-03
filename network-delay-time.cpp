/*
Title: Network delay Time
Link: https://leetcode.com/problems/network-delay-time/
*/

//Using Dijkstra's Algorithm with Priority Queue and Adjacency List
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        // Convert given data to adjacency list
        for(auto time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back(pair<int, int>{v, w});
        }

        unordered_set<int> visited;
        //Use min heap to pop the smallest element
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> weights(n, INT_MAX);
        // Insert the source node to priority queue
        pq.push(make_pair(0, k));
        weights[k-1] = 0;
        
        while(!pq.empty()){
            // Pop the node with least weight
            auto temp = pq.top();
            pq.pop();

            int node = temp.second;
            int weight = temp.first;

            // If the node has been visited then ignore else mark it as visited
            if(visited.find(node) != visited.end()){
                continue;
            }
            visited.insert(node);

            // Loop though the neighbors and put them into the queue along with updating the weights
            for(auto neighbor: adj[node]){
                int adjnode = neighbor.first;
                int adjweight = neighbor.second;
                weights[adjnode-1] = min(weights[adjnode-1], weights[node-1] + adjweight);
                pq.push(make_pair(weights[adjnode-1], adjnode));
            }
        }

        int minTime = 0;

        for(int w: weights){
            if(w == INT_MAX){
                return -1;
            }
            else{
                minTime = max(minTime, w);
            }
        }

        return minTime;
    }
};

// Using Bellman Ford Algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        // Construct the adjaceny list
        for(auto time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        // Create a wieghts array witn default value as infinity and source value as 0
        vector<int> weights(n, INT_MAX);
        weights[k-1] = 0;

        // Push the source node t oqueue
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            // Pop the node from the queue
            int currnode = q.front();
            q.pop();
            int currweight = weights[currnode-1];

            // Check all the neighbors of the popped node
            for(pair<int, int> neighbor: adj[currnode]){
                int neighnode = neighbor.first;
                int neighweight = neighbor.second;

                // If the neighbor node distance is greater than the popped node ditance + edge value from popped node to neighbor node then update the weight and also push it into the queue again for updating the subsequent set of values again
                if(currweight + neighweight < weights[neighnode-1]){
                    weights[neighnode-1] = currweight + neighweight;
                    q.push(neighnode);
                }
            }
        }

        int minTime = 0;

        for(int w: weights){
            if(w == INT_MAX){
                return -1;
            }
            else{
                minTime = max(minTime, w);
            }
        }

        return minTime;
    }
};
