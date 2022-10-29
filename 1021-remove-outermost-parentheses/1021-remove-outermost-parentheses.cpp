class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        vector<string> cont;
        string a = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push('(');
            } else if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                }
            }
            a += s[i];
            if(st.empty()) {
                cont.push_back(a);
                a = "";
            }
        }
        string res = "";
        for(auto x: cont) {
            res += x.substr(1, x.length() - 2);
        }
        return res;
    }
};