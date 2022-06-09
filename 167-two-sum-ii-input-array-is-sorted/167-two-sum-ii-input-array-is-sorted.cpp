class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if(nums.at(start) + nums.at(end) == target) {
                return {start + 1, end + 1};
            } else if (nums.at(start) + nums.at(end) < target) {
                start++;
            } else {
                end--;
            }
        }
        return {};
    }
};