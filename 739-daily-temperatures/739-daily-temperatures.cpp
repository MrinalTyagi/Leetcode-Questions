class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res;
        for(int i = temperatures.size() - 1; i>=0; i--) {
            while(!s.empty() && temperatures.at(s.top()) <= temperatures.at(i)) {
                s.pop();
            }
            int t = (s.empty()) ? 0 : s.top() - i;
            res.push_back(t);
            s.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};