/*
Title: Time based Key-Value Store
Link: https://leetcode.com/problems/time-based-key-value-store
*/

class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(map.find(key) == map.end()){
            return "";
        }

        int low = 0;
        int high = map[key].size() - 1;
        string result = "";

        while(low <= high){
            int mid = low + ((high-low)/2);

            if(map[key][mid].first <= timestamp){
                result = map[key][mid].second;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return result;
    }
};
