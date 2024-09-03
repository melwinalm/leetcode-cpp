/*
Title: Asteroid Collision
Link: https://leetcode.com/problems/asteroid-collision
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int asteroid: asteroids){
            bool isAlive = true;

            while(!st.empty() && asteroid < 0 && st.top() > 0){
                if(st.top() < -asteroid){
                    st.pop();
                    continue;
                }
                else if(st.top() == -asteroid){
                    st.pop();
                }
                isAlive = false;
                break;
            }

            if(isAlive){
                st.push(asteroid);
            }
        }

        vector<int> output;

        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }

        reverse(output.begin(), output.end());

        return output;
    }
};
