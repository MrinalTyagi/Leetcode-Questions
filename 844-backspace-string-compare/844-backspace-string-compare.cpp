class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '#') {
                if(!st.empty()) {
                  st.pop();   
                }
            } else {
                st.push(s.at(i));
            }
        }
        stack<char> rt;
        for(int i = 0; i < t.length(); i++) {
            if(t.at(i) == '#') {
                if(!rt.empty()) {
                  rt.pop();   
                }
            } else {
                rt.push(t.at(i));
            }
        }
        string f = "";
        while(!st.empty()) {
            f+=st.top();
            st.pop();
        }
        string r = "";
        while(!rt.empty()) {
            r+=rt.top();
            rt.pop();
        }
        return (f == r);
    }
};