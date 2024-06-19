/*
Title: Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self
*/

//Using Prefix and Sufix Array

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> output(n);

        for(int i = 0; i < n; i++){
            output[i] = prefix[i] * suffix[i];
        }

        return output;
    }
};

// Using Prefix and Suffix array by using output array itself instead of extra space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> output(n, 1);

        for(int i = 1; i < n; i++){
            output[i] = output[i-1] * nums[i-1];
        }

        int curr = 1;
        for(int i = n-1; i >= 0; i--){
            output[i] = output[i] * curr;
            curr *= nums[i];
        }

        return output;
    }
};
