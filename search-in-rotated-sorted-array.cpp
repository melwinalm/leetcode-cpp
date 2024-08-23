/*
Title: Search in a Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(target == nums[mid]){
                return mid;
            }

            if(nums[low] <= nums[mid]){ // Check Left portion
                if(target > nums[mid] || target < nums[low]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{ // Check Right portion
                if(target < nums[mid] || target > nums[high]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }

        return -1;
    }
};
