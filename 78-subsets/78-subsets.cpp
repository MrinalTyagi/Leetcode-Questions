class Solution {
public:
    
    
    void helper(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        if(index >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        ans.push_back(ds);
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums.at(i - 1) == nums.at(i)) {
                continue;
            }
            ds.push_back(nums.at(i));
            helper(i + 1, nums, ans, ds);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, nums, ans, ds);
        return ans;
    }
};