class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        string t = "";
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) != ' ') {
                start = i;
                break;
            }
        }
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s.at(i) != ' ') {
                end = i;
                break;
            }
        }
        for(int i = start; i <= end; i++) {
            if(s.at(i) == ' ') {
                if(count == 0) {
                    t+=' ';
                } 
                count++;
            } else {
                count = 0;
                t+=s.at(i);
            }
        }
        cout<<t<<endl;
        s = t; 
        start = 0, end = 0;
        while(end < s.length()) {
            if(s.at(end) == ' ') {
                for(int i = start, j = end - 1; i<=j; i++, j--) {
                    char temp = s.at(i);
                    s.at(i) = s.at(j);
                    s.at(j) = temp;
                }
                start = end + 1;
                end++;
            } else {
                end++;
            }
        }
        for(int i = start, j = end - 1; i<=j; i++, j--) {
            char temp = s.at(i);
            s.at(i) = s.at(j);
            s.at(j) = temp;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};