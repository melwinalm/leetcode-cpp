/*
Title: First Bad Version
Link: https://leetcode.com/problems/first-bad-version
*/

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        int output = n;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid)){
                output = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return output;
    }
};
