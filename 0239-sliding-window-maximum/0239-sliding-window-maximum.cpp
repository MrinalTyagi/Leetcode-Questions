class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int, greater<int>> pq;
        for(int i = 0; i < k; i++) {
            pq.insert(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            res.push_back(*pq.begin());
            pq.erase(pq.find(nums[i - k]));
            pq.insert(nums[i]);
        }
        res.push_back(*pq.begin());
        return res;
    }
};