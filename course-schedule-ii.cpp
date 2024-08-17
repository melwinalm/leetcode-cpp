/*
Title: Course Schedule II
Link: https://leetcode.com/problems/course-schedule-ii
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        unordered_map<int, vector<int>> map;

        for(vector<int> preq: prerequisites){
            int start = preq[1];
            int end = preq[0];

            indegree[end]++;

            map[start].push_back(end);
        }

        queue<int> bfs;
        vector<int> output;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                bfs.push(i);
                output.push_back(i);
            }
        }

        while(bfs.size() > 0){
            int curr = bfs.front();
            bfs.pop();

            for(int item: map[curr]){
                indegree[item]--;

                if(indegree[item] == 0){
                    bfs.push(item);
                    output.push_back(item);
                }
            }
        }

        return output.size() == numCourses ? output : vector<int>();
    }
};
