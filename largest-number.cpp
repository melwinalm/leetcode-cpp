/*
Title: Largest Number
Link: https://leetcode.com/problems/largest-number/
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string sa = to_string(a);
            string sb = to_string(b);

            return sa + sb > sb + sa;
        });

        string output = "";

        for(int num: nums){
            output += to_string(num);
        }

        while(output[0] == '0' && output.size() > 1){
            output.erase(0,1);
        }

        return output;
    }
};
