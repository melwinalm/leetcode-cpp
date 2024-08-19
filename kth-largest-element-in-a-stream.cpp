/*
Title: Kth Largest Element in a Stream
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        
        for(int num: nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size){
            pq.pop();
        }

        return pq.top();
    }
};
