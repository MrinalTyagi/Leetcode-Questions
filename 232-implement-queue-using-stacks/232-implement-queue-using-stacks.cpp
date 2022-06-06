class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(s.empty()) {
            return 0;
        }
        stack<int> r;
        while(!s.empty()) {
            if(s.size() == 1) {
                break;
            }
            int t = s.top();
            s.pop();
            r.push(t);
        }
        int temp = s.top();
        s.pop();
        while(!r.empty()) {
            int t = r.top();
            r.pop();
            s.push(t);
        }
        return temp;
    }
    
    int peek() {
        if(s.empty()) {
            return 0;
        }
        stack<int> r;
        while(!s.empty()) {
            if(s.size() == 1) {
                break;
            }
            int t = s.top();
            s.pop();
            r.push(t);
        }
        int temp = s.top();
        while(!r.empty()) {
            int t = r.top();
            r.pop();
            s.push(t);
        }
        return temp;
    }
    
    bool empty() {
       return (s.size() == 0); 
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