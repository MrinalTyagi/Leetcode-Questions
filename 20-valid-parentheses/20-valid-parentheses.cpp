class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                st.push(s.at(i));
            } else {
                if(s.at(i) == ')') {
                    if(!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (s.at(i) == '}') {
                    if(!st.empty() && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (s.at(i) == ']') {
                    if(!st.empty() && st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return (st.empty()) ? true : false;
    }
};