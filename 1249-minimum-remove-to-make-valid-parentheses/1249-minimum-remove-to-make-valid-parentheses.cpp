class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == '(') {
                count++;
            } else if(s.at(i) == ')') {
                if(count == 0) {
                    s.at(i) = '#';
                } else {
                    count--;
                }
            }
        }
        count = 0;
        for(int i = s.length() - 1; i>= 0; i--) {
            if(s.at(i) == ')') {
                count++;
            } else if(s.at(i) == '(') {
                if(count == 0) {
                    s.at(i) = '#';
                } else {
                    count--;
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};