/*
Title: Insert Delete GetRandom O(1) 
Link: https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

class RandomizedSet {
private:
    unordered_map<int,int> map;
    vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) == map.end()){
            int index = arr.size();
            arr.push_back(val);
            map[val] = index;

            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()){
            return false;
        }
        else{
            int index = map[val];
            map.erase(val);
            
            // if not last item
            if(index != arr.size() - 1){
                int lastitem = arr[arr.size()-1];
                arr[index] = lastitem;
                map[lastitem] = index;
            }
            arr.pop_back();

            return true;
        }
    }
    
    int getRandom() {
        int random = rand() % arr.size();
        return arr[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
