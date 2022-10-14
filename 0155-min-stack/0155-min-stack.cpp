class MinStack {
public:
    int minimum;
    stack<int> s1, s2;
    
    MinStack() {
        minimum = INT_MAX;
    }
    
    void push(int val) {
        if(val <= minimum) {
            s1.push(val);
            s2.push(val);
            minimum = val;
        } else {
            s1.push(val);
        }
    }
    
    void pop() {
        if(s1.top() == s2.top()) {
            s1.pop();
            s2.pop();
            minimum = (s2.empty() ? INT_MAX : s2.top());
        } else {
            s1.pop();
        }
    }
    
    int top() {
        if(s1.empty()) {
            return INT_MAX;
        }
        return s1.top();
    }
    
    int getMin() {
        if(s2.empty()) {
            return INT_MAX;
        }
        return s2.top();
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