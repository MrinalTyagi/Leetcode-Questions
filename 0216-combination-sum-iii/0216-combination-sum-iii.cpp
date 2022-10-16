class Solution {
public:
    
    void helper(int index, vector<int> arr, vector<vector<int>> &res, int sum, vector<int> &a, int k) {
        if(sum == 0) {
            if(a.size() == k) {
                res.push_back(a);
            }
            return;
        }
        
        if(sum < 0) {
            return;
        }
        
        if(index >= arr.size()) {
            return;
        }
        a.push_back(arr[index]);
        helper(index + 1, arr, res, sum - arr[index], a, k);
        a.pop_back();
        helper(index + 1, arr, res, sum, a, k);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        vector<vector<int>> res;
        vector<int> a;
        for(int i = 1; i <= 9; i++) {
            arr.push_back(i);
        }
        helper(0, arr, res, n, a, k);
        return res;
    }
};