/*
Title: Contiguous Array
Link: https://leetcode.com/problems/contiguous-array/
*/

// Prefix sum + Hashmap
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int output = 0;
        int sum = 0;

        unordered_map<int,int> map;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }

            if(sum == 0){
                output = i + 1;
            }
            if(map.find(sum) == map.end()){
                map[sum] = i;
            }
            else{
                output = max(output, i - map[sum]);
            }
        }

        return output;
    }
};
