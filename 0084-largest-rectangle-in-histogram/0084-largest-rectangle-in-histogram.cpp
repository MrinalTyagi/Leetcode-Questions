class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> prev(heights.size(), 0);
        vector<int> next(heights.size(), 0);
        for(int i = 0; i < heights.size(); i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            } 
            int a = (s.empty() ? -1 : s.top());
            prev[i] = a;
            s.push(i);
        }
        while(!s.empty()) {
            s.pop();
        }
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            int a = (s.empty() ? heights.size() : s.top());
            next[i] = a;
            s.push(i);
        }
        int res = 0;
        for(int i = 0; i < prev.size(); i++) {
            int inter = ((i - prev[i]) * heights[i]) + ((next[i] - i) * heights[i]) - heights[i];
            res = max(res, inter);
        }
        return res;
    }
};