/*
Title: Maximum Number of Words you Can Type
Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type
*/

class Solution {

private:
    vector<string> split(string input, char c){
        vector<string> output;

        int j = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == c){
                output.push_back(input.substr(j, i - j));
                j = i+1;
            }
        }

        output.push_back(input.substr(j, input.size() - j));
        return output;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> set;

        for(char c: brokenLetters){
            set.insert(c);
        }
    
        vector<string> split_text = split(text, ' ');
        int count = 0;

        for(int i = 0; i < split_text.size(); i++){
            bool flag = true;
            for(int j = 0; j < split_text[i].size(); j++){
                if(set.find(split_text[i][j]) != set.end()){
                    flag = false;
                    break;
                }
            }

            if (flag == true){
                count++;
            }
        }

        return count;
    }
};
