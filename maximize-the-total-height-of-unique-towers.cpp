class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), [](int val1, int val2){
            return val1 > val2;
        });

        int currHeight = maximumHeight[0];
        long output = 0;

        for(int height: maximumHeight){
            if(currHeight <= 0){
                return -1;
            }

            currHeight = min(currHeight, height);
            output += currHeight;

            currHeight--;
        }

        return output;
    }
};
