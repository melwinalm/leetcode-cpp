/*
Title: Evaluate Reverse Polish Notation
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation
*/

Using stack

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                int eval;

                if(token == "+"){
                    eval = num1 + num2;
                }
                else if(token == "-"){
                    eval = num2 - num1;
                }
                else if(token == "*"){
                    eval = num1 * num2;
                }
                else if(token == "/"){
                    eval = num2 / num1;
                }

                st.push(eval);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
