/*
Title: Min Stack
Link: https://leetcode.com/problems/min-stack
*/

class MinStack {
public:

    stack<int> originalStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty()){
            minStack.push(val);
        }
        else{
            minStack.push(min(val, minStack.top()));
        }
        originalStack.push(val);
    }
    
    void pop() {
        minStack.pop();
        originalStack.pop();
    }
    
    int top() {
        return originalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
