class Solution {
public:
    
    void helper(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int k) {
        if(ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if(index >= nums.size() || ds.size() > k) {
            return;
        }
        
        ds.push_back(nums.at(index));
        helper(index + 1, nums, ans, ds, k);
        ds.pop_back();
        helper(index + 1, nums, ans, ds, k);
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        helper(0, nums, ans, ds, k);
        return ans;
    }
};