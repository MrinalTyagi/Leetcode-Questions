class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        int minVal = min(numRows, int(s.size()));
        vector<string> rows(minVal, "");
        int currRow = 0;
        bool goingDown = false;
        for(char c : s) {
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += (goingDown == true) ? 1 : -1;
        }
        string t = "";
        for(int i = 0; i < rows.size(); i++) {
            t += rows.at(i);
        }
        return t;
    }
};