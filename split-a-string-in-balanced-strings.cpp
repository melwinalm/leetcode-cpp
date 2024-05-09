class Solution {
public:
    int balancedStringSplit(string s) {
        int output = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            count += s[i] == 'L' ? 1 : -1;

            if(count == 0){
                output++;
            }
        }

        return output;
    }
};
