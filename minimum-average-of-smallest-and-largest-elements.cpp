/*
Title: Minimum Average of Smallest and Largest Elements
Link: https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements
*/

// Sort and two pointers

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        
        double minSoFar = INT_MAX;
        
        for(int i = 0; i < N; i++){
            double first = double(nums[i]);
            double second = double(nums[N - i - 1]);
            minSoFar = min(minSoFar, (first + second)/2);
        }
                                      
        return minSoFar;
    }
};
