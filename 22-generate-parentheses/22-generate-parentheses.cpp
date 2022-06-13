class Solution {
public:     
    bool isValid(string &s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '(') {
                st.push(s.at(i));
            } else if(s.at(i) == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return (st.empty());
    }
    
    void helper(int s, vector<string> &ans, string &ds) {
        if(ds.length() == s) {
            if(isValid(ds)) {
                ans.push_back(ds);   
            }
            return;
        }
        ds.push_back('(');
        helper(s, ans, ds);
        ds.pop_back();
        ds.push_back(')');
        helper(s, ans, ds);
        ds.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        helper(n * 2, ans, ds);
        sort(ans.begin(), ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;
    }
};