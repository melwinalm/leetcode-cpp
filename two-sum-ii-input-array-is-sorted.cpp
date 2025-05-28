/*
Title: Two Sum II - Input Array Is Sorted
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

// Two Pointer Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        vector<int> output;

        while(i < j){
            int tempSum = numbers[i] + numbers[j];
            if(tempSum == target){
                output.push_back(i+1);
                output.push_back(j+1);
                return output;
            }
            else if(tempSum < target){
                i++;
            }
            else{
                j--;
            }
        }

        return output;
    }
};
