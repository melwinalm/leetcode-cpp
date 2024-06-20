/*
Title: Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        
        return st2.top();
    }
    
    bool empty() {
        return st1.size() + st2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
