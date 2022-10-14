class Solution {
public:
    bool isValid(string s) {
        stack<char> valid;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                valid.push(s[i]);
            } else if(s[i] == ')') {
                if(valid.empty() || valid.top() != '(') {
                    return false;
                }
                valid.pop();
            } else if(s[i] == '}') {
                if(valid.empty() || valid.top() != '{') {
                    return false;
                }
                valid.pop();
            } else if(s[i] == ']') {
                if(valid.empty() || valid.top() != '[') {
                    return false;
                }
                valid.pop();
            }
        }
        if(!valid.empty()) {
            return false;
        }
        return true;
    }
};