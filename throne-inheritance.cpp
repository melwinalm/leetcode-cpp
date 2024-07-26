/*
Title: Throne Inheritance
Link: https://leetcode.com/problems/throne-inheritance/
*/

// Using BFS Algorithm (Time Limit Exceeded)
class Tree{
public:
    bool isAlive;
    string name;
    vector<Tree*> children;

    Tree(string n){
        isAlive = true;
        name = n;
    }
};

class ThroneInheritance {

private:
    Tree* root;

public:
    ThroneInheritance(string kingName) {
        root = new Tree(kingName);
    }
    
    void birth(string parentName, string childName) {
        Tree* curr = root;

        queue<Tree*> q;
        q.push(curr);

        while(q.size() != 0){
            Tree* temp = q.front();
            q.pop();

            if(temp->name == parentName){
                Tree* newChild = new Tree(childName);
                temp->children.push_back(newChild);
                return;
            }
            else{
                for(auto child: temp->children){
                    q.push(child);
                }
            }
        }
    }
    
    void death(string name) {
        Tree* curr = root;

        queue<Tree*> q;
        q.push(curr);


        while(q.size() != 0){
            Tree* temp = q.front();
            q.pop();

            if(temp->name == name){
                temp->isAlive = false;
                return;
            }

            for(auto child: temp->children){
                q.push(child);
            }
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> output;

        Tree* curr = root;
        PreOrderTraversal(curr, output);

        return output;
    }

    void PreOrderTraversal(Tree* curr, vector<string>& output){
        if(curr == NULL){
            return;
        }

        if(curr->isAlive){
            output.push_back(curr->name);
        }

        for(auto child: curr->children){
            PreOrderTraversal(child, output);
        }
    }
};

// Using Unordered map
class Tree{
public:
    string name;
    vector<Tree*> children;

    Tree(string n){
        name = n;
    }
};

class ThroneInheritance {

private:
    Tree* root;
    unordered_map<string, Tree*> map;

public:
    ThroneInheritance(string kingName) {
        root = new Tree(kingName);
        map[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Tree* newChild = new Tree(childName);
        map[parentName]->children.push_back(newChild);
        map[childName] = newChild;
    }
    
    void death(string name) {
        if(map.find(name) != map.end()){
            map[name] = NULL;
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> output;

        Tree* curr = root;
        PreOrderTraversal(curr, output);

        return output;
    }

    void PreOrderTraversal(Tree* curr, vector<string>& output){
        if(curr == NULL){
            return;
        }

        if(map[curr->name] != NULL){
            output.push_back(curr->name);
        }

        for(auto child: curr->children){
            PreOrderTraversal(child, output);
        }
    }
};
