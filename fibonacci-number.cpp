/*
Title: Fibonacci Number
Link: https://leetcode.com/problems/fibonacci-number
*/

class Solution {
public:
    int fib2(int n, vector<int>& memo){
        if(memo[n] != -1){
            return memo[n];
        }
        else{
            return fib2(n-1, memo) + fib2(n-2, memo);
        }
    }

    int fib(int n) {
        if(n < 2){
            return n;
        }

        vector<int> memo(n+1, -1);
        memo[0] = 0;
        memo[1] = 1;

        return fib2(n, memo);
    }
};
