class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size(), -1);
        for(int i = nums.size() - 2; i >= 0; i--) {
            while(!s.empty() && s.top() < nums.at(i)) {
                s.pop();
            }
            s.push(nums.at(i));
        }
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums.at(i)) {
                s.pop();
            }
            if(s.empty()) {
                res.at(i) = -1;
            } else {
                res.at(i) = s.top();
            }
            s.push(nums.at(i));
        }
        return res;
    }
};