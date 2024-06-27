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
