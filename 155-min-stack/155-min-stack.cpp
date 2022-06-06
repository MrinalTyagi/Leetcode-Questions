class MinStack {
public:
    stack<int> a;
    stack<int> b;
    MinStack() {
        
    }
    
    void push(int val) {
        if(a.empty()) {
            a.push(val);
            b.push(val);
            return;
        } 
        a.push(val);
        if(val <= b.top()) {
            b.push(val);
        } 
    }
    
    void pop() {
        if(a.empty()) {
            return;
        }
        if(a.top() == b.top()) {
            b.pop();
        }
        a.pop();
    }
    
    int top() {
        if(a.empty()) {
            return 0;
        }
        return a.top();
    }
    
    int getMin() {
        if(b.empty()) {
            return 0;
        }
        return b.top();
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