/*
Title: Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapper{{'(',')'}, {'{', '}'}, {'[',']'}};

        stack<char> st;

        for(char c: s){
            if(mapper.find(c) != mapper.end()){
                st.push(mapper[c]);
            }
            else{
                if(st.size() == 0 || st.top() != c){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }

        return st.size() == 0;
    }
};

// Elegant solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c: s){
            if(c == '('){
                st.push(')');
            }
            else if(c == '['){
                st.push(']');
            }
            else if(c == '{'){
                st.push('}');
            }
            else{
                if(st.size() > 0 && c == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};
