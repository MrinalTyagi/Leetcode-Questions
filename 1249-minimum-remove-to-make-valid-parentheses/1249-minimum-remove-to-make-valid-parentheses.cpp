class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count1 = 0, count2 = 0;
        for(int i = 0, j = s.length() - 1; i < s.length(); i++, j--) {
            if(s.at(i) == '(') {
                count1++;
            } else if(s.at(i) == ')') {
                if(count1 == 0) {
                    s.at(i) = '#';
                } else {
                    count1--;
                }
            }
            if(s.at(j) == ')') {
                count2++;
            } else if(s.at(j) == '(') {
                if(count2 == 0) {
                    s.at(j) = '#';
                } else {
                    count2--;
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};