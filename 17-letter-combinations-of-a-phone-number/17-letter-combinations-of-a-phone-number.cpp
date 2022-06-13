class Solution {
public:
    unordered_map<char, string> m;
    
    void helper(int index, string &digits, vector<string> &ans, string &ds) {
        if(index >= digits.length()) {
            ans.push_back(ds);
            return;
        }
        string v = m[digits.at(index)];
        for(int i = 0; i < v.length(); i++) {
            ds.push_back(v.at(i));
            helper(index + 1, digits, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds = "";
        if(digits.length() == 0 ){
            return ans;
        }
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        helper(0, digits, ans, ds);
        return ans;
    }
};