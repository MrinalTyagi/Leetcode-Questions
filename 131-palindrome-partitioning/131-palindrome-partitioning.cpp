class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void helper(int index, string &s, vector<vector<string>> &ans, vector<string> &ds) {
        if(index >= s.length()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));
                helper(i + 1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0, s, ans, ds);
        return ans;
    }
};