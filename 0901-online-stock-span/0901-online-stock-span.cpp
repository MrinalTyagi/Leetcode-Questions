class StockSpanner {
public:
    stack<int> s;
    vector<int> span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!s.empty() && span[s.top()] <= price) {
            s.pop();
        }  
        span.push_back(price);
        int res = (s.empty() ? span.size(): span.size() - s.top() - 1); 
        s.push(span.size() - 1);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */