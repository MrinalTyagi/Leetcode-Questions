class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '(') {
                st.push(i);
            } else if(s.at(i) == ')') {
                if(!st.empty() && s.at(st.top()) == '(') {
                    st.pop();
                } else {
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        while(!st.empty()) {
            for(int i = s.length() - 1; i>= 0; i--) {
                if(s.at(i) == s.at(st.top())) {
                   s.erase(i, 1);
                    break;
                }
            }
            st.pop();
        }
        return s;
    }
};