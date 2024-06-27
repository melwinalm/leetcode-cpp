/*
Title: Kth Largest Element in an Array
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// Using sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int i, int j){
            return i > j;
        });

        return nums[k-1];
    }
};

// Using Priority Queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int num: nums){
            pq.push(num);
        }

        int output;

        while(k > 0){
            output = pq.top();
            pq.pop();
            k--;
        }

        return output;
    }
};
