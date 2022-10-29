class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = 0;
        for(; i < s.length(); i++) {
            if(s[i] != ' ') {
                break;
            }
        }
        for(; i < s.length(); i++) {
            if(s[i] == ' ') {
                if((i == s.length() - 1 || s[i + 1] == ' ')) {
                    
                } else {
                    res += s[i];
                }
            } else {
                res += s[i];
            }
        } 
        s = res;
        int first = 0, second = 0;
        i = 0;
        for(; i < s.length(); i++) {
            if(s[i] == ' '){
                second = i - 1;
                while(first <= second) {
                    char temp = s[first];
                    s[first] = s[second];
                    s[second] = temp;
                    first++;
                    second--;
                }
                first = i + 1;
            }
        }
        second = i - 1;
        while(first <= second) {
            char temp = s[first];
            s[first] = s[second];
            s[second] = temp;
            first++;
            second--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};