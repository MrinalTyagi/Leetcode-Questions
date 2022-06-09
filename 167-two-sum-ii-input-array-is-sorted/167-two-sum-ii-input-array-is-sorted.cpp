class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        vector<int> res;
        while(start <= end) {
            if(nums.at(start) + nums.at(end) == target) {
                res.push_back(start + 1);
                res.push_back(end + 1);
                return res;
            } else if (nums.at(start) + nums.at(end) < target) {
                start++;
            } else {
                end--;
            }
        }
        return res;
    }
};