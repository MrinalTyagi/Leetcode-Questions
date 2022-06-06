class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!s.empty() && nums2[s.top()] <= nums2[i]) {
                s.pop();
            }
            int t = (s.empty()) ? -1 : nums2[s.top()];
            map[nums2[i]] = t;
            s.push(i);
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1.at(i) = map[nums1.at(i)];
        }
        return nums1;
    }
};