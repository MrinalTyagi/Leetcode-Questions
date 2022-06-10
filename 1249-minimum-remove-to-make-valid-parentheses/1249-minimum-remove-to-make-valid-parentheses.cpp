class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t = "";
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '(') {
                t += '(';
                st.push(i);
            } else if(s.at(i) == ')') {
                if(!st.empty() && s.at(st.top()) == '(') {
                    t += ')';
                    st.pop();
                }
            } else {
                t+=s.at(i);
            }
        }
        while(!st.empty()) {
            for(int i = t.length() - 1; i>= 0; i--) {
                if(t.at(i) == s.at(st.top())) {
                   t.erase(i, 1);
                    break;
                }
            }
            st.pop();
        }
        return t;
    }
};