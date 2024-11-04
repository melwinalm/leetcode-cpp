// Link: https://leetcode.com/problems/check-balanced-string

class Solution {
public:
    bool isBalanced(string num) {
        int oddSum = 0;
        int evenSum = 0;

        for(int i = 0; i < num.size(); i++){
            if(i%2 == 0){
                evenSum += int(num[i] - '0');
            }
            else{
                oddSum += int(num[i] - '0');
            }
        }

        return oddSum == evenSum;
    }
};
