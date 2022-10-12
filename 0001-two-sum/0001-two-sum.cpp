class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(s.count(target - nums[i])) {
                res.push_back(s[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            s.insert({nums[i], i});
        }
        return res;
    }
};