/*
Title: Redundant Connection
Link: https://leetcode.com/problems/redundant-connection
*/

// Using Union Find
class UnionFind{
public:
    vector<int> parent;

    UnionFind(int n){
        parent = vector<int>(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int Find(int node){
        while(node != parent[node]){
            node = parent[node];
        }

        return node;
    }

    bool UnionizeIfDifferentParent(int x, int y){
        int px = Find(x);
        int py = Find(y);

        if(px == py){
            return false;
        }

        parent[px] = py;
        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;

        for(auto edge: edges){
            n = max({n, edge[0], edge[1]});
        }

        UnionFind uf(n+1);

        for(auto edge: edges){
            // If two nodes have same parent then that's the edge which is converting it to a graph
            if(!uf.UnionizeIfDifferentParent(edge[0], edge[1])){
                return edge;
            }
        }

        return {0, 0};
    }
};
