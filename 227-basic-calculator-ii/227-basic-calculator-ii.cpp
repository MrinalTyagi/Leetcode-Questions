class Solution {
public:
    
    bool isOperator(char s) {
        return (s == '+' || s == '-' || s == '*' || s == '/') ? true : false;
    }
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/") ? true : false;
    }
    
    int priority(char s) {
        if(s == '+' || s == '-') {
            return 1;
        } else {
            return 2;
        }
    }
    
    int calculate(string s) {
        stack<char> st;
        string t = "";
        for(int i = 0; i < s.length(); i++) {
            if(isOperator(s.at(i))) {
                while(!st.empty() && priority(st.top()) >= priority(s.at(i))) {
                    char a = st.top();
                    st.pop();
                    t+=' ';
                    t+=a;
                }
                t += ' ';
                st.push(s.at(i));
            } else if(s.at(i) != ' ') {
                t += s.at(i);
            }
        }
        while(!st.empty()) {
            t += ' ';
            t += st.top();
            st.pop();
        }
        for(int i = 0; i < t.length(); i++) {
            cout<<t.at(i);
        }
        cout<<endl;
        stack<int> f;
        for(int i = 0; i < t.length(); i++) {
            string a = "";
            while(i < t.length() && t.at(i) != ' ') {
                a += t.at(i);
                i++;
                cout<<a<<endl;
            }
           
            if(isOperator(a)) {
                int second = f.top();
                f.pop();
                int first = f.top();
                f.pop();
                int res = 0;
                if(a == "+") {
                    res = first + second;
                } else if(a == "-") {
                    res = first - second;
                } else if(a == "*") {
                    res = first * second;
                } else {
                    res = first / second;
                }
                f.push(res);
            } else {
                 int v = stoi(a);
                 f.push(v);
            }
        }
        return f.top();
    }
};