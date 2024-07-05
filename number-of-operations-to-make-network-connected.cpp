/*
Title: Number of Operations to make Network Connected
Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

// Using union find with path compression and union by rank size
class UnionFind{
public:
    int componentCount;
    vector<int> parent;
    vector<int> size;

    UnionFind(int n){
        componentCount = n;
        parent = vector<int>(n);
        size = vector<int>(n);

        // Initially set the parent of all the nodes to itslef
        // Set the size of the nodes to 1
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int node){
        int root = node;

        // Find the parent of node until you find a node whose parent is itself
        while(root != parent[root]){
            root = parent[root];
        }

        // Applying Path Compression
        // Update the parent of all the nodes to the root node that was found
        while(node != root){
            int temp = parent[node];
            parent[node] = root;
            node = temp;
        }

        return node;
    }

    void Union(int x, int y){
        int parentX = Find(x);
        int parentY = Find(y);

        // If both have same parent, then do nothing
        if(parentX == parentY){
            return;
        }

        // Applying Union By Rank Approach
        if(size[parentX] > size[parentY]){
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        }
        else{
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }

        // Everytime a new union is made the connected component count reduces
        componentCount--;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // You need atleast n-1 edges available to make connection with all the nodes
        if(connections.size() < n-1){
            return -1;
        }

        UnionFind uf(n);

        for(auto edge: connections){
            uf.Union(edge[0], edge[1]);
        }

        // If there are x number of connected components, then you need x-1 edges to connect them
        return uf.componentCount - 1;
    }
};
