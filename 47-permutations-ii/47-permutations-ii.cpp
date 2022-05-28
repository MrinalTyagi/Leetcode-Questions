class Solution {
public:
    
    void swap(int &a1, int &a2) {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    
    
    void helper(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        if(index >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums.at(i - 1) == nums.at(i)) {
                continue;
            }
            swap(nums.at(index), nums.at(i));
            ds.push_back(nums.at(index));
            helper(index + 1, nums, ans, ds);
            ds.pop_back();
            swap(nums.at(index), nums.at(i));
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(0, nums, ans, ds);
        sort( ans.begin(), ans.end() );
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;
    }
};