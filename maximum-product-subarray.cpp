/*
Title: Maximum Prduct Subarray
Link: https://leetcode.com/problems/maximum-product-subarray/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int minimum = nums[0];
        int maximum = nums[0];
        int maxSoFar = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < 0){
                swap(minimum, maximum);
            }

            minimum = min(nums[i], nums[i] * minimum);
            maximum = max(nums[i], nums[i] * maximum);

            maxSoFar = max(maxSoFar, maximum);
        }

        return maxSoFar;
    }
};
