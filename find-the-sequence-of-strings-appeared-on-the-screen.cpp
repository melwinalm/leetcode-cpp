class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> output;

        if(target == ""){
            return output;
        }

        int N = target.size();

        for(int i = 0; i < N; i++){
            string startString;
            if(i == 0){
                startString = "";
            }
            else{
                startString = output[output.size()-1];
            }

            int currentChar = int('a');
            int requiredChar = int(target[i]);

            while(currentChar <= requiredChar){
                output.push_back(startString + char(currentChar));
                currentChar++;
            }
        }

        return output;
    }
};
