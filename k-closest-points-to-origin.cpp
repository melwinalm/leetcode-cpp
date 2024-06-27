/*
Title: K Closest Points to Origin
Link: https://leetcode.com/problems/k-closest-points-to-origin
*/

// Using Priority Queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(auto point: points){
            int x = point[0];
            int y = point[1];

            int distance = pow(x, 2) + pow(y, 2);
            
            pq.push({distance, {x, y}});
        }

        vector<vector<int>> output;

        while(k > 0){
            auto item = pq.top();
            pq.pop();

            int x = item.second.first;
            int y = item.second.second;
            output.push_back(vector<int>{x, y});

            k--;
        }

        return output;
    }
};
