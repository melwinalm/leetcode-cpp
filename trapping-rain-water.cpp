/*
Title: Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water
*/

Best link for explanation - https://leetcode.com/problems/trapping-rain-water/solutions/1374608/c-java-python-maxleft-maxright-so-far-with-picture-o-1-space-clean-concise

// Using DP
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();

        if(N <= 2){
            return 0;
        }

        vector<int> left(N);
        vector<int> right(N);

        left[0] = height[0];
        right[N-1] = height[N-1];

        for(int i = 1; i < N; i++){
            left[i] = max(height[i], left[i-1]);
        }

        for(int i = N-2; i >= 0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        int maxWater = 0;

        for(int i = 0; i < N; i++){
            maxWater += min(left[i], right[i]) - height[i];
        }

        return maxWater;
    }
};

// Two Pointer Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();

        if(N <= 2){
            return 0;
        }

        int left = 1;
        int right = N-2;
        int maxLeft = height[0];
        int maxRight = height[N-1];

        int maxWater = 0;

        while(left <= right){
            if(maxLeft < maxRight){
                if(height[left] < maxLeft){
                    maxWater += maxLeft - height[left];
                }
                else{
                    maxLeft = height[left];
                }
                left++;
            }
            else{
                if(height[right] < maxRight){
                    maxWater += maxRight - height[right];
                }
                else{
                    maxRight = height[right];
                }
                right--;
            }
        }

        return maxWater;
    }
};
