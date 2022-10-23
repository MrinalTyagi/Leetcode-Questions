class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++) {
            pq.push(nums.at(i));
        }
        for(int i = k; i < nums.size(); i++) {
            if(nums.at(i) > pq.top()) {
                pq.pop();
                pq.push(nums.at(i));
            }
        }
        return pq.top();
    }
};