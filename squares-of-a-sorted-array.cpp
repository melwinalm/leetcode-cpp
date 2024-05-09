// Naive
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output(nums.size());

        for(int i = 0; i < nums.size(); i++){
            output.push_back(nums[i] * nums[i]);
        }

        sort(output.begin(), output.end());

        return output;
    }
};

// Two pointer approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> output(N);

        int a = 0;
        int b = N-1;
        for(int i = N-1; i >= 0; i--){
            if(abs(nums[a]) > abs(nums[b])){
                output[i] = nums[a] * nums[a];
                a++;
            }
            else{
                output[i] = nums[b] * nums[b];
                b--;
            }
        }

        return output;
    }
};
