class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> res;
        for(int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            while(!s.empty() && curr != 0 && (curr < 0 && s.top() > 0)) {
                int temp = s.top();
                s.pop();
                if((temp == -1 * curr) || (curr == -1 * temp)) {
                    curr = 0;
                } else if(abs(temp) > abs(curr)) {
                    curr = temp;
                } 
            }
            if(curr != 0) {
                s.push(curr);
            }
        }
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};