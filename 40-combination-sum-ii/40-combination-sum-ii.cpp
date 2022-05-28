class Solution {
public:
    
    
    void helper(int index, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        if(index >= candidates.size()) {
            return;
        }
        
        for(int i = index; i < candidates.size(); i++) {
            if(target < candidates.at(i)) {
                break;
            }
            if(i > index && candidates.at(i - 1) == candidates.at(i)) {
                continue;
            }
            ds.push_back(candidates.at(i));
            helper(i + 1, candidates, ans, ds, target - candidates.at(i));
            ds.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, ans, ds, target);
        return ans;
    }
};