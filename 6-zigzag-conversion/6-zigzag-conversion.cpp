class Solution {
public:
    string convert(string s, int numRows) {
        string t = "";
        for(int i = 0; i < numRows - 1; i++) {
            int j = 0;
            while(j < s.length() && s.at(j) == '#') {
                j++;
            }
            bool isFirst = true;
            while(j < s.length()) {
                if(s.at(j) != '#') {
                    t += s.at(j);   
                }
                s.at(j) = '#';
                if(isFirst) {
                    j = j + ((numRows - (i + 1)) * 2);   
                } else {
                    j = j + (2 * i);
                }
                isFirst = !isFirst;
            }
        }
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) != '#') {
                t += s.at(i);
            }
        }
        return t;
    }
};