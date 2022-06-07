class StockSpanner {
public:
    stack<pair<int, int>> s;
    int count;
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        while(!s.empty() && s.top().first <= price) {
            s.pop();
        }
        int val = (s.empty()) ? count + 1 : count - s.top().second;
        pair<int, int> p;
        p.first = price;
        p.second = count;
        s.push(p);
        count++;
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */