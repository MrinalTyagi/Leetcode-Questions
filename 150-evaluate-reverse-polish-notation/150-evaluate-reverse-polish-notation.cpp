class Solution {
public:
    
    bool isOperator(string s) {
        if(s == "+" || s == "-" || s == "*" || s == "/") {
            return true;
        }
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if(isOperator(tokens.at(i))) {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                int res = 0;
                if(tokens.at(i) == "+") {
                    res = first + second;
                } else if(tokens.at(i) == "-") {
                    res = first - second;
                } else if(tokens.at(i) == "*") {
                    res = first * second;
                } else if(tokens.at(i) == "/") {
                    res = first / second;
                }
                s.push(res);
            } else {
                s.push(stoi(tokens.at(i)));
            }
        }
        return s.top();
    }
};