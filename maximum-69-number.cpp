// Convert to string and replace
class Solution {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);

        for(int i = 0; i < numString.size(); i++){
            if(numString[i] == '6'){
                numString[i] = '9';
                break;
            }
        }

        return stoi(numString);
    }
};
