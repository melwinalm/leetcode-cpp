/*
Title: Clone Graph
Link: https://leetcode.com/problems/clone-graph/
*/

// Using Depth First Search
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        
        unordered_map<Node*, Node*> map;

        dfs(map, node);

        return map[node];
    }

    void dfs(unordered_map<Node*, Node*>& map, Node* node){
        Node* copyNode = new Node(node->val);
        map[node] = copyNode;

        for(Node* n: node->neighbors){
            if(map.find(n) == map.end()){
                dfs(map, n);
            }
            copyNode->neighbors.push_back(map[n]);
        }
    }
};
