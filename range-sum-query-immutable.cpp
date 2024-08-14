/*
Title: Range Sum Query - Immutable
Link: https://leetcode.com/problems/range-sum-query-immutable
*/

// Using Prefix Sum
class NumArray {
private:
    vector<int> rangeSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->rangeSum.push_back(nums[0]);
        
        for(int i = 1; i < n; i++){
            this->rangeSum.push_back(this->rangeSum[i-1] + nums[i]);
        }

    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return this->rangeSum[right];
        }
        else{
            return this->rangeSum[right] - this->rangeSum[left-1];
        }
    }
};
