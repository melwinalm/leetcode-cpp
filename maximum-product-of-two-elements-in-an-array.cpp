/*
Title: Maximum Product of Two Elements in an Array
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
*/

// Using Priority Queue
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(int num: nums){
            pq.push(num);
        }

        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        
        return (num1 - 1) * (num2 - 1);
    }
};
