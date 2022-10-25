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
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int f = 0;
        vector<int> res(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '0') {
                    res[j] = 0;
                } else {
                    res[j] += 1;
                }
            }
            int result = largestRectangleArea(res);
            f = max(f, result);
        }
        return f;
    }
};