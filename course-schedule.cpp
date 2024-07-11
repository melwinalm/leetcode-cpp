/*
Title: Course Schedule
Link: https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, vector<int>> adj;

        // Create adjacency list
        // Also update indegree array to keep a count of number of edges coming towards an node
        for(auto preq: prerequisites){
            int a = preq[0];
            int b = preq[1];

            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        // Put all the nodes with in degree 0 to the queue, since those courses are not dependent on any other
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;

        while(!q.empty()){
            int course = q.front();
            q.pop();

            visited++;

            // As you loop though the neighbours of a node decrease it's in degrees. If a indegree becomes 0 then push it to the queue
            for(int edge: adj[course]){
                indegree[edge]--;

                if(indegree[edge] == 0){
                    q.push(edge);
                }
            }
        }

        // If all indegrees are 0 then all courses can be taken else it means there are circular dependencies
        return visited == numCourses;
    }
};
