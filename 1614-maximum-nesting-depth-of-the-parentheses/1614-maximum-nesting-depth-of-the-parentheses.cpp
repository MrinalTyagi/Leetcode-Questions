class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                if(st.size() > res) {
                    res = st.size();
                }
            } else if(s[i] == ')') {
                st.pop();
            }
        }
        return res;
    }
};