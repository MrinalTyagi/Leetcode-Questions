class Solution {
public:
    void generate(int n, int l, int r, string &ds, vector<string> &ans) {
        if(l == n & r == n) {
            ans.push_back(ds);
        } else {
            if(l < n) {
                ds.push_back('(');
                generate(n, l + 1, r, ds, ans);
                ds.pop_back();
            }
            if(r < l) {
                ds.push_back(')');
                generate(n, l, r + 1, ds, ans);
                ds.pop_back();
            }
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        generate(n, 0, 0, ds, ans);
        return ans;
    }
};