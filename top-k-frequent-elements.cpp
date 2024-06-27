/*
Title: Top K Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements
*/

// Using Priority Queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int num: nums){
            map[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto item: map){
            pq.push(make_pair(item.second, item.first));
        }

        vector<int> output;

        while(k > 0 && !pq.empty()){
            pair<int, int> temp = pq.top();
            pq.pop();

            output.push_back(temp.second);
            k--;
        }

        return output;
    }
};
