class Solution {
public:
    
    void helper(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        if(index >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        helper(index + 1, nums, ans, ds);
        ds.push_back(nums.at(index));
        helper(index + 1, nums, ans, ds);
        ds.pop_back();
    }    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(0, nums, ans, ds);
        sort(ans.begin(), ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;
    }
};