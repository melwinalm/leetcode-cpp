/*
Title: Backspace String Compare
Link: https://leetcode.com/problems/backspace-string-compare
*/

//Using Stack
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stacks;
        stack<char> stackt;

        for(char c: s){
            if(c == '#'){
                if(!stacks.empty()){
                    stacks.pop();
                }
            }
            else{
                stacks.push(c);
            }
        }

        for(char c: t){
            if(c == '#'){
                if(!stackt.empty()){
                    stackt.pop();
                }
            }
            else{
                stackt.push(c);
            }
        }

        while(!stacks.empty() && !stackt.empty()){
            if(stacks.top() != stackt.top()){
                return false;
            }
            stacks.pop();
            stackt.pop();
        }

        return stacks.size() == 0 && stackt.size() == 0;
    }
};
