class Solution {
private:
    int getSum(int num){
        int output = 0;

        while(num > 0){
            output += (num % 10);
            num /= 10;
        }

        return output;
    }

public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;

        for(int num: nums){
            result = min(result, getSum(num));
        }

        return result;
    }
};
