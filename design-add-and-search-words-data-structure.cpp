/*
Title: Design Add and Search Words Data Structure
Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

struct TrieNode{
    TrieNode* children[26];
    bool isWord;

    TrieNode(){
        isWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(TrieNode* node, string word, int i){
        if(i == word.size()){
            return node->isWord;
        }

        char c = word[i];
        if(c == '.'){
            for(int j = 0; j < 26; j++){
                if(node->children[j] != NULL && searchHelper(node->children[j], word, i+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(node->children[c-'a'] != nullptr){
                return searchHelper(node->children[c-'a'], word, i+1);
            }
            else{
                return false;
            }
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* tempRoot = root;
        for(char c: word){
            if(tempRoot->children[c-'a'] == NULL){
                tempRoot->children[c-'a'] = new TrieNode();
            }
            
            tempRoot = tempRoot->children[c-'a'];
        }

        tempRoot->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* tempRoot = root;
        return searchHelper(tempRoot, word, 0);
    }
};
