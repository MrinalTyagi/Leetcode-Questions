class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for(int i  = nums2.size() - 1; i >= 0; i--) {
            if (i == nums2.size() - 1) {
                m[nums2.at(i)] = -1;
            } else {
                while(!s.empty() && s.top() < nums2.at(i)) {
                    s.pop();
                }
                if(s.empty()) {
                    m[nums2.at(i)] = -1;
                } else {
                    m[nums2.at(i)] = s.top();
                }
            }
            s.push(nums2.at(i));
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1.at(i) = m[nums1.at(i)];
        }
        return nums1;
    }
};