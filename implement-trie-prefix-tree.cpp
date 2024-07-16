/*
Title: Implement Trie (Prefix Tree)
Link: https://leetcode.com/problems/implement-trie-prefix-tree
*/

class Node{
public:
    bool isEnd;
    Node* values[26] = {NULL};

    Node(){
        isEnd = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tempNode = root;

        for(char c: word){
            if(tempNode->values[c - 'a'] == NULL){
                tempNode->values[c - 'a'] = new Node();;
            }

            tempNode = tempNode->values[c - 'a'];
        }

        tempNode->isEnd = true;
    }
    
    bool search(string word) {
        Node* tempNode = root;

        for(char c: word){
            if(tempNode->values[c - 'a'] == NULL){
                return false;
            }

            tempNode = tempNode->values[c - 'a'];
        }

        return tempNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* tempNode = root;

        for(char c: prefix){
            if(tempNode->values[c - 'a'] == NULL){
                return false;
            }
            tempNode = tempNode->values[c - 'a'];
        }

        return true;
    }
};
